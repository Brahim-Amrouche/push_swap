#include "tester.h"
#include "ft_printf.h"

void mandatory()
{
    print_white();
    printf("Mandatory ------------------------------------------------------\n");
    // BREAKERS
    printf("No format Tests ---------- \n");
    print_test_result(ft_printf("hello") == 5,"Basic run : simple 'hello' print");
    print_test_result(ft_printf("")== 0 , "Basic run : empty string");
    print_test_result(ft_printf(NULL)== -1,"Basic run : NULL string pointer as first parameter");
    print_test_result(ft_printf("hello there % lx") >= 0,"Basic run : Not handled converter");
    print_test_result(ft_printf("still %lu %n s") >= 0 , "Basic run : Another Not handled converters");
    print_test_result(ft_printf("%")== 0,"Basic run : % before the \\0");
    // %c converter
    print_white();
    printf("Char Tests ----------- \n");
    print_test_result(ft_printf("%c") == 1,"Char converter without a parametre passed");
    print_test_result(ft_printf("%c",'a') == 1,"Char converter with parameter passed");
    print_test_result(ft_printf("%c",'\1') == printf("%c",'\1'),"Char converter with ascii value of unprintable char");
    print_test_result(ft_printf("%c",0) == printf("%c",0),"Char converter Printin null char");
    print_test_result(ft_printf("%c",-10) == printf("%c",-10),"Printin negative char");
    // %s converter
    print_white();
    printf("String Tests --------- \n");
    print_test_result(ft_printf("%s",NULL)== 6,"String converter with NULL");
    print_test_result(ft_printf("%s","") == 0,"String modifier with empty string");
    print_test_result(ft_printf("%s", "Hello World") == 11 , "String converter with Simple :Hello World");
    char *s = "Hello World this is unprintable \2 and this also \3 but this is printable \060";
    print_test_result((size_t) ft_printf("%s", s) == strlen(s) , "String converter with unpritable ascii chars and simple strings");
    // %p converter
    print_white();
    printf("Pointer Tests ----------- \n");
    print_test_result(ft_printf("%p"), "Address converter with no value passed");
    print_test_result(ft_printf("%p",NULL) == printf("%p",NULL) , "Address converter With null value");
    print_test_result(ft_printf("%p",s) == printf("%p",s) , "Address converter with pointer value");
    // %d converter
    print_white();
    printf("Decimal Tests %%d ---------- \n");
    print_test_result(ft_printf("%d"),"Decimal converter with no value passed");
    print_test_result(ft_printf("%d",0)== 1,"Decimal converter with value passed");
    print_test_result(ft_printf("%d",07)== 1,"Decimal converter with octal value");
    print_test_result(ft_printf("%d",0xf)== 2,"Decimal converter with hex value value");
    print_test_result(ft_printf("%d",69)== 2,"Decimal converter with postive value passed");
    print_test_result(ft_printf("%d",-69)== 3,"Decimal converter with negative value passed");
    print_test_result(ft_printf("%d",INT_MAX)== printf("%d",INT_MAX) , "Decimal converter with MAX INT");
    print_test_result(ft_printf("%d",INT_MIN)== printf("%d",INT_MIN) , "Decimal converter with MIN INT");
    print_test_result(ft_printf("%d",-2147483648 - 2) == 10, "Decimal converter with Negative Overflow");
    print_test_result(ft_printf("%d",INT_MAX + 2) == 11 , "Decimal converter with Positive Overflow");
    // %i converter
    print_white();
    printf("Integer Tests %%i ---------- \n");
    print_test_result(ft_printf("%i"),"Integer converter with no value passed");
    print_test_result(ft_printf("%i",0)== 1,"Integer converter with value passed");
    print_test_result(ft_printf("%i",07)== 1,"Integer converter with octal value");
    print_test_result(ft_printf("%i",0xf)== 2,"Integer converter with hex value value");
    print_test_result(ft_printf("%i",69)== 2,"Integer converter with postive value passed");
    print_test_result(ft_printf("%i",-69)== 3,"Integer converter with negative value passed");
    print_test_result(ft_printf("%i",INT_MAX)== printf("%d",INT_MAX) , "Integer converter with MAX INT");
    print_test_result(ft_printf("%i",INT_MIN)== printf("%d",INT_MIN) , "Integer converter with MIN INT");
    print_test_result(ft_printf("%i",-2147483648 - 2) == 10, "Integer converter with Negative Overflow");
    print_test_result(ft_printf("%i",INT_MAX + 2) == 11 , "Integer converter with Positive Overflow");
    // %u converter
    print_white();
    printf("Unsigned Integer Test ----------- \n");
    print_test_result(ft_printf("%u") >= 0,"Unsigned Integer converter with no value passed");
    print_test_result(ft_printf("%u",0) == 1,"Unsigned Integer converter with zero as value");
    print_test_result(ft_printf("%u",69) == printf("%u",69),"Unsigned Integer converter with positive value passed");
    print_test_result(ft_printf("%u",-1) == printf("%u",-1),"Unsigned Integer converter with negative value passed");
    print_test_result(ft_printf("%u",UINT_MAX) == printf("%u",UINT_MAX),"Unsigned Integer converter with UINT_MAX");
    print_test_result(ft_printf("%u",4294967295 + 2) == 1,"Unsigned Integer converter with Overflow");
    // %x
    print_white();
    printf("Hexadecimal LowerCase Test ----------- \n");
    print_test_result(ft_printf("%x")>= 0 , "Hexadcimal LowerCase Converter with no value passed");
    print_test_result(ft_printf("%x",0) == 1 , "Hexadcimal LowerCase Converter with value zero");
    print_test_result(ft_printf("%x",15) == printf("%x",15) , "Hexadcimal LowerCase Converter with positive value");
    print_test_result(ft_printf("%x",-69) == printf("%x",-69) , "Hexadcimal LowerCase Converter with negative value");
    // %X
    print_white();
    printf("Hexadecimal UpperCase Test ----------- \n");
    print_test_result(ft_printf("%X")>= 0 , "Hexadcimal UpperCase Converter with no value passed");
    print_test_result(ft_printf("%X",0) == 1 , "Hexadcimal UpperCase Converter with value zero");
    print_test_result(ft_printf("%X",15) == printf("%X",15) , "Hexadcimal UpperCase Converter with positive value");
    print_test_result(ft_printf("%X",-69) == printf("%X",-69) , "Hexadcimal UpperCase Converter with negative value");
    
    // %%
    print_white();
    printf("Percentage Test ----------- \n");
    print_test_result(ft_printf("%%")== 1 , "Percentage Converter");

    // Mixed Tests
    s = "%c|%s|%p|%d|%i|%u|%x|%X|%%";
    print_test_result(ft_printf(s,'a',"hello",s,10,10,10,-1,-1) == 48,"All Flags in one");

    // BREAKERS
    print_white();
    printf("End mandatory ---------------------------------------------------\n");
    print_black();
}