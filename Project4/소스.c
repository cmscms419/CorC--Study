#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <sys/types.h>
#include <winsock2.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define BUF 30
#define MAX 1024

typedef struct hosttable
{
	struct hostent table;
	int hit;
} hosttable;

void error_handling(char* message);
int yorn(char c, char str[], hosttable htable[], struct hostent* myhost);
int Dcheck(hosttable htable[], char str[], struct hostent* myhost);
void tableprint(int m, hosttable htable[]);
void insertionSort(hosttable htable[], int htai);


void hostprint(char str[], struct hostent* myhost, int htai, hosttable htable[], struct in_addr myinaddr);
void addrprint(char str[], struct hostent* myhost, int htai, hosttable htable[], struct sockaddr_in addr);

int main(int argc, char* argv[])
{
	struct hostent* myhost = NULL;
	struct in_addr myinaddr; //IP 주소를 저장할 구조체
	struct sockaddr_in addr;

	hosttable htable[MAX];

	int htai = 0;
	char c;
	char str[BUF];

	while (1)
	{
		printf("domain address(d or D) and IP address(a or A) Q or q exit\n");
		scanf(" %c", &c);

		if (c == 'Q' || c == 'q')
			exit(1);
		else if (c == 'd' || c == 'D')
		{
			printf("Domain Address: ");
			scanf("%s", str);

			if (str == NULL)
			{
				printf("Usage : %s \n", str);
				exit(1);
			}

			if (yorn(c, str, htable, myhost) == 1)
			{
				continue;
			}
			else
			{
				hostprint(str, myhost, htai, htable, myinaddr);
				puts("");
			}
			htai++;
		}
		else if (c == 'a' || c == 'A')
		{
			printf("IP Address: ");
			scanf("%s", str);

			if (str == NULL)
			{
				printf("Usage : %s \n", str);
				exit(1);
			}
		}

		insertionSort(htable, htai);

		for (int i = 0; i < BUF; i++)
		{
			str[i] = ' ';
		}
	}
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
}

void addrprint(char str[], struct hostent* myhost, int htai, hosttable htable[], struct sockaddr_in addr)
{
	memset(&addr, 0, sizeof(addr));
	addr.sin_addr.s_addr = inet_addr(str);

	myhost = gethostbyaddr((char*)&addr.sin_addr, 4, AF_INET);

	if (!myhost)
	{
		error_handling("gethost... error");
		exit(1);
	}
	printf("Officially name : %s \n\n", myhost->h_name);
	puts("Aliases-----------");

	for (int i = 0; myhost->h_aliases[i]; i++)
	{
		puts(myhost->h_aliases[i]);
	}

	printf("Address Type : %s \n", myhost->h_addrtype == AF_INET ? "AF_INET" : "AF_INET6");
	puts("IP Address--------");

	for (int i = 0; myhost->h_addr_list[i]; i++)
	{
		puts(inet_ntoa(*(struct in_addr*)myhost->h_addr_list[i]));
	}
	puts("");
}

void hostprint(char str[], struct hostent* myhost, int htai, hosttable htable[], struct in_addr myinaddr)
{
	int i;

	//host
	myhost = gethostbyname(str);

	if (myhost == 0)
	{
		printf("erro occurs .. at 'get host by name'.\n\n");
		exit(1);
	}

	// 호스트 이름 출력
	printf("official host name : \t\t %s\n\n", myhost->h_name);
	i = 0;
	//호스트 별명 출력
	while (myhost->h_aliases[i] != NULL)
	{
		printf("aliases name : \t\t%s\n", myhost->h_aliases[i]);
		i++;
	}

	//호스트 주소체계 출력
	printf("host address type : \t\t%d\n", myhost->h_addrtype);
	//호스트 주소 길이 출력
	printf("length of host address : \t%d\n", myhost->h_length);
	//호스트 주소를 dotted decimal 형태로 출력
	i = 0;

	while (myhost->h_addr_list[i] != NULL)
	{
		myinaddr.s_addr = *((u_long*)(myhost->h_addr_list[i]));
		printf("address for host:\t\t%s\n", inet_ntoa(myinaddr));
		i++;
	}

	htable[htai].table = *myhost;
	htable[htai].hit = 0;
}

int yorn(char c, char str[], hosttable htable[], struct hostent* myhost)
{
	int i = 0;

	if (c == 'd' || c == 'D')
	{
		i = Dcheck(htable, str, myhost);
		if (i >= 0)
		{
			printf("123\n\n");
			tableprint(i, htable);
			return 1;
		}
	}
	else if (c == 'a' || c == 'A')
	{

	}

	return 0;
}

int Dcheck(hosttable htable[], char str[], struct hostent* myhost)
{
	myhost = gethostbyname(str);

	int tablesize = sizeof(htable) / sizeof(hosttable);

	printf("%s\nDcheck\n", myhost->h_name);

	for (int i = 0; i < tablesize; i++)
	{
		if (strcmp(htable[i].table.h_name, myhost->h_name) == 0)
			return i;
	}

	return -1;
}

void tableprint(int m, hosttable htable[])
{
	struct in_addr myinaddr;
	int i = 0;

	// 호스트 이름 출력
	printf("official host name : \t\t %s\n\n", htable[m].table.h_name);
	//호스트 별명 출력
	while (htable[m].table.h_aliases[i] != NULL)
	{
		printf("aliases name : \t\t%s\n", htable[m].table.h_aliases[i]);
		i++;
	}

	//호스트 주소체계 출력
	printf("host address type : \t\t%d\n", htable[m].table.h_addrtype);
	//호스트 주소 길이 출력
	printf("length of host address : \t%d\n", htable[m].table.h_length);
	//호스트 주소를 dotted decimal 형태로 출력
	i = 0;

	while (htable[m].table.h_addr_list[i] != NULL)
	{
		myinaddr.s_addr = *((u_long*)(htable[m].table.h_addr_list[i]));
		printf("address for host:\t\t%s\n", inet_ntoa(myinaddr));
		i++;
	}

	htable[m].hit++;
}

void insertionSort(hosttable htable[], int htai)
{

	int y = 0;
	hosttable sub;

	for (int i = 1; i < htai; i++)
	{
		sub = htable[i];
		y = i - 1;

		while (y >= 0 && htable[y].hit < sub.hit)
		{
			htable[y + 1] = htable[y];
			y--;
		}
		htable[y + 1] = sub;
	}

}