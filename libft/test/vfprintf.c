//usr/bin/cc $0 -O0 -g -fsanitize=address -Iinclude -L. -lftprintf -o ./a.out	&& ./a.out; exit
//usr/bin/cc $0 -O0 -g -Iinclude -L. -lft -o ./a.out	&& ./a.out; exit

#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_memory.h"
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int add_cnt(int);

char	fcmp(const char *f1, const char *f2)
{
	printf("======================================\n");
	int	ret;
	char c1, c2;
	FILE *fp1, *fp2;

	fp1 = fopen(f1, "r");
	fp2 = fopen(f2, "r");
	if (fp1 == NULL || fp2 == NULL)
	{
		printf("Error: One or both of the files can't be used \n ");
		return (-1);
	}
	ret = 0;
	c1 = getc(fp1);
	c2 = getc(fp2);
	while ((c1 != EOF) && (c2 != EOF))
	{
		if (c1 != c2)
		{
			printf("\nError: not same charactor\n");
			printf("  %s: '%c'(%d)\n", f1, c1, c1);
			printf("  %s: '%c'(%d)\n", f2, c2, c2);
			ret = EOF;
		}
		else
			fputc(isprint(c1)?c1:'.', stdout);
		c1 = getc(fp1);
		c2 = getc(fp2);
	}
	fclose(fp1);
	fclose(fp2);
	printf("\n");
	if (c1 != EOF)
	{
		printf("Error: '%s' does not end by '%c'(%d)\n", f1, c1, c1);
		ret = EOF;
	}
 	if(c2 != EOF)
	{
		printf("Error: '%s' does not end by '%c'(%d)\n", f2, c2, c2);
		ret = EOF;
	}
	return (ret);
}

int	test_vfprintf(const char *restrict f, ...)
{
	int	std_ret;
	int	ft_ret;
	int	ret;

	va_list ap1, ap2;
	FILE *f1, *f2;
	f1 = fopen("/tmp/vfprintf.txt", "w");
	f2 = fopen("/tmp/ft_vfprintf.txt", "w");
	va_start(ap1, f);
	std_ret = vfprintf(f1, f, ap1);
	fflush(f1);
	fclose(f1);
	va_end(ap1);
	va_start(ap2, f);
	ft_ret = ft_vfprintf(f2, f, ap2);
	ft_fflush(f2);
	fclose(f2);
	va_end(ap2);
	ret = fcmp("/tmp/vfprintf.txt", "/tmp/ft_vfprintf.txt");
	if (std_ret != ft_ret)
	{
		printf("Error: return values are not same\n");
		printf("  std:%d, ft:%d\n", std_ret, ft_ret);
		ret = -1;
	}
	if(ret)
	{
		printf("%s\n", f);
		exit(ret);
	}
	return (ret);
}

int strlen_test(size_t s)
{
	char *p;

	p = malloc(s + 1);
	if(!p)
		return 0;
	memset(p, '*', s);
	p[s] = 0;
	printf("==== test print size: '%lu' ====\n", s);
	test_vfprintf(p);
	
	free(p);
	return 0;
	//return test_vfprintf("%s%saiueo%saiueo", p,p,p);
}

int	main(void)
{
	//strlen_test(((size_t)1<<31) - 1);
	//strlen_test(((size_t)1<<31));
	//strlen_test(((size_t)1<<31) + 1);
//ft_printf("asdsaf");
test_vfprintf("%.3s", "didsfgsaf");
test_vfprintf("%-5c", '\0');
test_vfprintf("{%3c}", 0);
	return 0;
test_vfprintf("%p", ULONG_MAX);

test_vfprintf("%-135p" ,(void*)166017542380380199lu);
test_vfprintf("%-48p%-164c" ,(void*)9888845855039847185lu,114);
test_vfprintf("%104.60s%109c%-9p" ,"}&@/h\n\f<C",36,(void*)14251011342640672780lu);
test_vfprintf("%131p%--.42u%65c%-68c%-7c" ,(void*)14631880201060661778lu,1668628755u,110,-16,-32);
test_vfprintf("%--189p" ,(void*)8440737604753056005lu);
test_vfprintf("%64p%038.87d%23c%--182.49i%--76.110%" ,(void*)10278319775164267212lu,-1550079501,30,-862355787);
test_vfprintf("%-120p" ,(void*)5150423256795085944lu);
test_vfprintf("%120p%--55.128i" ,(void*)9377650025287837451lu,816352753);
test_vfprintf("%--63p%-62.182d" ,(void*)1199013529227388230lu,568134778);
test_vfprintf("%-166.180X%--18.47d%---111.87%%8p%0114.24X" ,1637127682u,-1931431309,(void*)3522468094256045905lu,4291674618u);
test_vfprintf("%29p%0151.162x%---53.46u%-139.26X" ,(void*)17894711340605174765lu,1565093748u,662758369u,3536629372u);
test_vfprintf("%-p%-35p%00042.14i%p" ,(void*)1508633298498623712lu,(void*)4610270612598633961lu,-1053760970,(void*)4955973954213917723lu);
test_vfprintf("%108p%-175.188i" ,(void*)11721873312409420167lu,-653373315);

test_vfprintf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130, (char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141, (char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152, (char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163, (char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174, (char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185, (char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196, (char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207, (char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218, (char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229, (char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240, (char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251, (char)252,(char)253,(char)254,(char)255);
test_vfprintf("%-135p" ,(void*)166017542380380199lu);
test_vfprintf("%-48p%-164c" ,(void*)9888845855039847185lu,114);
test_vfprintf("%104.60s%109c%-9p" ,"}&@/h\n\f<C",36,(void*)14251011342640672780lu);
test_vfprintf("%131p%--.42u%65c%-68c%-7c" ,(void*)14631880201060661778lu,1668628755u,110,-16,-32);
test_vfprintf("%--189p" ,(void*)8440737604753056005lu);
test_vfprintf("%64p%038.87d%23c%--182.49i%--76.110%" ,(void*)10278319775164267212lu,-1550079501,30,-862355787);
test_vfprintf("%-120p" ,(void*)5150423256795085944lu);
test_vfprintf("%120p%--55.128i" ,(void*)9377650025287837451lu,816352753);
test_vfprintf("%--63p%-62.182d" ,(void*)1199013529227388230lu,568134778);
test_vfprintf("%-166.180X%--18.47d%---111.87%%8p%0114.24X" ,1637127682u,-1931431309,(void*)3522468094256045905lu,4291674618u);
test_vfprintf("%29p%0151.162x%---53.46u%-139.26X" ,(void*)17894711340605174765lu,1565093748u,662758369u,3536629372u);
test_vfprintf("%-p%-35p%00042.14i%p" ,(void*)1508633298498623712lu,(void*)4610270612598633961lu,-1053760970,(void*)4955973954213917723lu);
test_vfprintf("%108p%-175.188i" ,(void*)11721873312409420167lu,-653373315);

test_vfprintf("this %i number", 17);
test_vfprintf("%i", 3);
test_vfprintf("this %d number", 17);
test_vfprintf("%i", 2147483647);
test_vfprintf("%i", (int)(-2147483678));
test_vfprintf("%7i", 33);
test_vfprintf("%5i", 52625);
test_vfprintf("%4i", 94827);
test_vfprintf("%-7i", 33);

test_vfprintf("%s", NULL);
test_vfprintf("%-s", NULL);
test_vfprintf("%23s", NULL);
test_vfprintf("%p", NULL);
test_vfprintf("%s", NULL);
test_vfprintf("hello, %s.", NULL);
test_vfprintf("%s", NULL);
test_vfprintf("%32s", NULL);
test_vfprintf("%2s", NULL);
test_vfprintf("%-32s", NULL);
test_vfprintf("%-16s", NULL);
test_vfprintf("%-3s", NULL);
test_vfprintf("%p", NULL);
test_vfprintf("Hello 42 school! %s", NULL);
test_vfprintf("%p\n", NULL);
test_vfprintf("%15p\n", NULL);
test_vfprintf("%-15p\n", NULL);
test_vfprintf("%10s", NULL);
test_vfprintf("%.p", NULL);
test_vfprintf("%.p", NULL);
test_vfprintf("%1.p", NULL);
test_vfprintf("%1.p", NULL);
test_vfprintf("%5.p", NULL);
test_vfprintf("%5.p", NULL);
test_vfprintf("-->|%-16.p|<-- ", NULL);
test_vfprintf("-->|%-16.p|<-- ", NULL);

test_vfprintf("%.0i", 1);
test_vfprintf("aiueo");
test_vfprintf("%%");
test_vfprintf("%.%");
test_vfprintf("%7.5%");
test_vfprintf("%-7.5%");
test_vfprintf("%07.5%");
test_vfprintf("%s", "aiiuew");
test_vfprintf("%.10s", "aiiuew");
test_vfprintf("%.s", NULL);
test_vfprintf("%7.5c", 42);
test_vfprintf("%-7.5c", 42);
test_vfprintf("%07.5c", 42);
test_vfprintf("%d", -42);
test_vfprintf("%d", INT_MAX);
test_vfprintf("%d", INT_MIN);
test_vfprintf("%7.5d", 4242);
test_vfprintf("%7.3d", 4242);
test_vfprintf("%07.5s", "4242");
test_vfprintf("%07.5%", "4242");
test_vfprintf("%07.5c", "42");
test_vfprintf("%07.5d", 4242);
test_vfprintf("%-7.5d", 4242);
test_vfprintf("%+7.5d", 4242);
test_vfprintf("% 7.5d", 4242);
test_vfprintf("%.c", 42);
test_vfprintf("%.x", 42);
test_vfprintf("%.X", 42);
test_vfprintf("%.d", 42);
test_vfprintf("%.i", 42);
test_vfprintf("%.u", 42);
test_vfprintf("%.p", 42);
test_vfprintf("%.%" );

test_vfprintf("%d", -42);
test_vfprintf("%d", 42);
test_vfprintf("%d", INT_MAX);
test_vfprintf("%d", INT_MIN);
test_vfprintf("%20d", 20);
test_vfprintf("%5s", "1234567890");
test_vfprintf("%015.15s", "12345");
test_vfprintf("%015.10s", "12345");
test_vfprintf("%015.5s", "12345");
test_vfprintf("%015.0s", "12345");
test_vfprintf("%015.15d", 12345);
test_vfprintf("%015.10d", 12345);
test_vfprintf("%015.0d", 12345);
test_vfprintf("%015d", 12345);
test_vfprintf("ai%s", "ueo");

test_vfprintf("%.3s", NULL);
test_vfprintf("%.3s", "hello");
test_vfprintf("%.s", "hello");
test_vfprintf("%.0s", "hello");
test_vfprintf("%.3s%.2s", "holla", "bitch");
test_vfprintf("%.2s%.7s", "hello", "world");
test_vfprintf("%.7s%.2s", "hello", "world");
test_vfprintf("%7.5s", "bombastic");
test_vfprintf("%-7.5s", "tubular");
test_vfprintf("%7.3s%7.7s", "hello", "world");
test_vfprintf("%3.3s%7.7s", "hello", "world");
test_vfprintf("%7.3s%3.7s", "hello", "world");
test_vfprintf("%3.3s%3.7s", "hello", "world");
test_vfprintf("%7.7s%7.3s", "hello", "world");
test_vfprintf("%3.7s%7.3s", "hello", "world");
test_vfprintf("%7.7s%3.3s", "hello", "world");
test_vfprintf("%3.7s%3.3s", "hello", "world");
test_vfprintf("%7.3s%7.3s", "hello", "world");
test_vfprintf("%3.3s%7.3s", "hello", "world");
test_vfprintf("%7.3s%3.3s", "hello", "world");
test_vfprintf("%3.3s%3.3s", "hello", "world");
test_vfprintf("%.3s", "NULL");
test_vfprintf("%.s", "NULL");
test_vfprintf("%.0s", "NULL");
test_vfprintf("%.03s", NULL);
test_vfprintf("%3.s", NULL);
test_vfprintf("%10.s", NULL);
test_vfprintf("%-3.s", NULL);
test_vfprintf("%-8.s", NULL);
test_vfprintf("%3.1s", NULL);
test_vfprintf("%9.1s", NULL);
test_vfprintf("%-3.1s", NULL);
test_vfprintf("%-9.1s", NULL);
test_vfprintf("%07i", -54);
test_vfprintf("%.1i", -54);
test_vfprintf("%c", '\0');

test_vfprintf("%.0i", 1);
test_vfprintf("%.0i", 0);
test_vfprintf("%.i", 0);
test_vfprintf("%5.0i", 0);
test_vfprintf("%5.i", 0);
test_vfprintf("%-5.0i", 0);
test_vfprintf("%-5.i", 0);
test_vfprintf("%07d", -54);
test_vfprintf("%.0d", 0);
test_vfprintf("%.d", 0);
test_vfprintf("%5.0d", 0);
test_vfprintf("%5.d", 0);
test_vfprintf("%-5.0d", 0);
test_vfprintf("%-5.d", 0);
test_vfprintf("this %u number", 17);
test_vfprintf("this %u number", 0);
test_vfprintf("%u", 3);
test_vfprintf("%u", 4294967295u);
test_vfprintf("%7u", 33);
test_vfprintf("%3u", 0);
test_vfprintf("%5u", 52625);
test_vfprintf("%4u", 94827);
test_vfprintf("%-7u", 33);
test_vfprintf("%-3u", 0);
test_vfprintf("%-5u", 52625);
test_vfprintf("%-4u", 94827);
test_vfprintf("%.5u", 2);
test_vfprintf("%.3u", 0);
test_vfprintf("%.4u", 5263);
test_vfprintf("%.3u", 13862);
test_vfprintf("%05u", 43);
test_vfprintf("%03u", 0);
test_vfprintf("%03u", 634);
test_vfprintf("%8.5u", 34);
test_vfprintf("%8.5u", 0);
test_vfprintf("%8.3u", 8375);
test_vfprintf("%3.7u", 3267);
test_vfprintf("%3.3u", 6983);
test_vfprintf("%-8.5u", 34);
test_vfprintf("%-8.5u", 0);
test_vfprintf("%-8.3u", 8375);
test_vfprintf("%-3.7u", 3267);
test_vfprintf("%-3.3u", 6983);
test_vfprintf("%08.5u", 34);
test_vfprintf("%08.5u", 0);
test_vfprintf("%08.3u", 8375);
test_vfprintf("%03.7u", 3267);
test_vfprintf("%03.3u", 6983);
test_vfprintf("%5.0u", 0);
test_vfprintf("%5.u", 0);
test_vfprintf("%-5.0u", 0);
test_vfprintf("%-5.u", 0);

test_vfprintf("%.0x", 0);
test_vfprintf("%.x", 0);
test_vfprintf("%5.0x", 0);
test_vfprintf("%5.x", 0);
test_vfprintf("%-5.0x", 0);
test_vfprintf("%-5.x", 0);
test_vfprintf("%.0x", 0);
test_vfprintf("%.x", 0);
test_vfprintf("%5.0x", 0);
test_vfprintf("%5.x", 0);
test_vfprintf("%-5.0x", 0);
test_vfprintf("%-5.x", 0);
test_vfprintf("%.0X", 0);
test_vfprintf("%.X", 0);
test_vfprintf("%5.0X", 0);
test_vfprintf("%5.X", 0);
test_vfprintf("%-5.0X", 0);
test_vfprintf("%-5.X", 0);
test_vfprintf("%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c",(char)128,(char)129,(char)130, (char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141, (char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152, (char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163, (char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174, (char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185, (char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196, (char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207, (char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218, (char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229, (char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240, (char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251, (char)252,(char)253,(char)254,(char)255);
test_vfprintf("%u", 42);
test_vfprintf("before %u after", 42);
test_vfprintf("%u%u%u%u%u", 1, 100, 999, 42, 999988888);
test_vfprintf("a%ub%uc%ud", 0, 55555, 100000);
test_vfprintf("%u", UINT_MAX);
test_vfprintf("{%010d}", -42);
test_vfprintf("%.d, %.0d", 0, 0);
test_vfprintf("%.i, %.0i", 0, 0);
test_vfprintf("%.4u", 42);
test_vfprintf("%.4u", 424242);
test_vfprintf("%15.4u", 42);
test_vfprintf("%15.4u", 424242);
test_vfprintf("%8.4u", 424242424);
test_vfprintf("%4.15u", 42);
test_vfprintf("%4.15u", 424242);
test_vfprintf("%4.8u", 424242424);
test_vfprintf("%.u, %.0u", 0, 0);
test_vfprintf("%.x, %.0x", 0, 0);
test_vfprintf("%.X, %.0X", 0, 0);
test_vfprintf("%.4s", "42 is the answer");
test_vfprintf("%15.4s", "I am 42");
test_vfprintf("%15.4s", "42 is the answer");
test_vfprintf("%4.15s", "42 is the answer");
test_vfprintf("%4.s", "42");
test_vfprintf("%u", -42);
test_vfprintf("%u", UINT_MAX + 1);
test_vfprintf("pp %.50d\n", 10000);
test_vfprintf("p3 %.4s\n", NULL);
test_vfprintf("p9 %.50d\n", 100);
test_vfprintf("p12 %.0d\n", 0);
test_vfprintf("p17 %.50i\n", 100);
test_vfprintf("p20 %.0x\n", 0);
test_vfprintf("p25 %.50x\n", 100);
test_vfprintf("p28 %.0x\n", 0);
test_vfprintf("p29 %.3u\n", 100);
test_vfprintf("p30 %.0u\n", 100);
test_vfprintf("p31 %.4u\n", 100);
test_vfprintf("p32 %.10u\n", 100);
test_vfprintf("p33 %.50u\n", 100);
test_vfprintf("p34 %.1u\n", 100);
test_vfprintf("p35 %.3u\n", 100);
test_vfprintf("p36 %.0u\n", 0);
test_vfprintf("%40.50d\n", 50);
test_vfprintf("%50.2s", "Coucou");
test_vfprintf("%50.2s", NULL);
test_vfprintf("%5.0s", "Hello");
test_vfprintf("%.1s", "Test");
test_vfprintf("t4 %50.50d\n", 10);
test_vfprintf("t7 %1.50d\n", -10);
test_vfprintf("t8 %1.50d\n", 10);
test_vfprintf("t12 %.0d\n", 0);
test_vfprintf("31 This is an int : %.0d\n\n", 0);
test_vfprintf("%u", 1024u);
test_vfprintf("%u", -1024u);
test_vfprintf("%1u", 1024u);
test_vfprintf("%1u", -1024u);
test_vfprintf("%20u", 1024u);
test_vfprintf("%20u", -1024u);
test_vfprintf("%-20u", 1024u);
test_vfprintf("%-20u", -1024u);
test_vfprintf("%020d", -1024);
test_vfprintf("%020i", -1024);
test_vfprintf("%020u", 1024u);
test_vfprintf("%020u", -1024u);
test_vfprintf("%.20u", 1024u);
test_vfprintf("%.20u", -1024u);
test_vfprintf("%20.5s", "Hallo heimur");
test_vfprintf("%20.5u", 1024u);
test_vfprintf("%20.5u", -1024u);
test_vfprintf("%020.5u", 1024u);
test_vfprintf("%020.5u", -1024u);
test_vfprintf("%.0s", "Hallo heimur");
test_vfprintf("%20.0s", "Hallo heimur");
test_vfprintf("%.s", "Hallo heimur");
test_vfprintf("%20.s", "Hallo heimur");
test_vfprintf("%20.d", 0);
test_vfprintf("%20.i", 0);
test_vfprintf("%20.u", 1024u);
test_vfprintf("%20.0u", -1024u);
test_vfprintf("%20.u", 0u);
test_vfprintf("%20.x", 0u);
test_vfprintf("%20.X", 0u);
test_vfprintf("%--194.54X" ,3852169892u);
test_vfprintf("%-114.24i%-174.164i" ,-608242235,-1247846882);

test_vfprintf("%-135p" ,(void*)166017542380380199lu);
test_vfprintf("%--73.154d" ,-1185050931);
test_vfprintf("%-78.100u%0091.158x" ,2490445787u,628341766u);
test_vfprintf("%012.84u" ,2880913598u);
test_vfprintf("%0176.18i%0131.59i%-86X%---45.36X" ,-1748967713,-1568187420,124888334u,2293430389u);
test_vfprintf("%--40.183X%-178.81X%036.192u%-119.27s" ,2684215029u,410939004u,2169426684u,"!ufvJeVr`+BF#EV");
test_vfprintf("%098.58d%--7.168d" ,549613177,850697743);
test_vfprintf("%-48p%-164c" ,(void*)9888845855039847185lu,114);
test_vfprintf("%-70.193x%-140c%168c%026.51%%0125.119X" ,1102840003u,-50,-17,3721437512u);
test_vfprintf("%104.60s%109c%-9p" ,"}&@/h\n\f<C",36,(void*)14251011342640672780lu);
test_vfprintf("%131p%--.42u%65c%-68c%-7c" ,(void*)14631880201060661778lu,1668628755u,110,-16,-32);
test_vfprintf("%---137.49s%-127.121X" ,"!^3W]E;3T;FBR(KBN|03|!us3&sT[",2181790462u);
test_vfprintf("%--189p" ,(void*)8440737604753056005lu);
test_vfprintf("%-38.146x" ,2598409833u);
test_vfprintf("%-162.188x%000140.102X" ,2533724638u,3512081841u);
test_vfprintf("%023.150x" ,945656380u);
test_vfprintf("%-50c%-85.157%%--58.188X" ,9,274691972u);
test_vfprintf("%64p%038.87d%23c%--182.49i%--76.110%" ,(void*)10278319775164267212lu,-1550079501,30,-862355787);
test_vfprintf("%---130.58X%173.67s%-181.87u%-30c" ,1925387529u,"|0py&+BlK7]j3X\vDK",282509935u,-111);
test_vfprintf("%-132.186x%00129.46%%-191.181X%-75.123d%0033.123u" ,2222238685u,3146675666u,251185067,3453417465u);
test_vfprintf("%-120p" ,(void*)5150423256795085944lu);
test_vfprintf("%045.81X" ,1608282792u);
test_vfprintf("%--198.101X%0145.12%%172c" ,935976394u,-118);
test_vfprintf("%120p%--55.128i" ,(void*)9377650025287837451lu,816352753);
test_vfprintf("%--60.36s%-86.108s%0091.147X" ,"ou=eS","Mq9\r",389939786u);
test_vfprintf("%0020.149u%-99.97i" ,2945319386u,-1913054753);
test_vfprintf("%-139.77X%-82.101x" ,4273984084u,639114854u);
test_vfprintf("%-64u" ,4204812483u);
test_vfprintf("%--180.61X" ,1396814909u);
test_vfprintf("%--63p%-62.182d" ,(void*)1199013529227388230lu,568134778);
test_vfprintf("%50.10s%-44.68x%--78.43s" ,"Fj&Xd",665370725u,"/p@_T=e=^Cf7!g>fDE");
test_vfprintf("%-166.180X%--18.47d%---111.87%%8p%0114.24X" ,1637127682u,-1931431309,(void*)3522468094256045905lu,4291674618u);
test_vfprintf("%-55.46%%--171.99s%--56.41X%-173X" ,"7",3917830995u,3557113666u);
test_vfprintf("%29p%0151.162x%---53.46u%-139.26X" ,(void*)17894711340605174765lu,1565093748u,662758369u,3536629372u);
test_vfprintf("%-10.123X%---155.97x" ,382459494u,970578181u);
test_vfprintf("%-188c%-84.159x%-.82i%-192.158i" ,45,2099602418u,-590423754,1933619156);
test_vfprintf("%-p%-35p%00042.14i%p" ,(void*)1508633298498623712lu,(void*)4610270612598633961lu,-1053760970,(void*)4955973954213917723lu);
test_vfprintf("%--71c%074.49X%-50.195x%-106.79i" ,-112,1537135483u,4281417478u,1103336433);
test_vfprintf("%0047.196X%0100.115u%--147.189u" ,4124736153u,3428700903u,661309797u);
test_vfprintf("%-198.190i" ,-915338234);
test_vfprintf("%0110.7u%-85.40X%---182.30s" ,1517824905u,3044934856u,".iM8/ct)(S");
test_vfprintf("%108p%-175.188i" ,(void*)11721873312409420167lu,-653373315);
test_vfprintf("%0134.185i%061.174d" ,1465312329,1402026716);
test_vfprintf("%.d", 0);
test_vfprintf("%.u", 1);
test_vfprintf("%.s", "aasf");
test_vfprintf("%1.u", 1);
test_vfprintf("%1.s", "aasf");
test_vfprintf("%5.u", 1);
test_vfprintf("%5.s", "aasf");
//*/
}
