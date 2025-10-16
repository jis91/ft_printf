#include "ft_printf.h"
#include "libft.h"

int     ft_print_char(int c)
{
        return (write(1, &c, 1));
}


int ft_print_str(const char *str)
{
    int i;

    i = 0;
    if (str == NULL)
    {
        write(1, "(NULL)", 6);
        return (-1);
    }
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    return (i);
}

int ft_print_nbr(int n)
{
    char *num;
    int length;
    
    length = 0;
    num = ft_itoa(n);
    length = ft_printstr(num);
    free(num);
    return (length);
}

int ft_printpercent(void)
{
    return (write(1, "%", 1));
}
/* These functions are helpers for print_pointer*/
static void ft_put_pointer(void *ptr)
{
    unsigned long long pointer;

    pointer = (unsigned long long)ptr;
    if (pointer >= 16)
    {
        ft_put_pointer(pointer / 16);
        ft_put_pointer(pointer % 16);
    }
    else
    {
        if (pointer <= 9)
        {
            ft_print_char((pointer + '0'));
        }
        else
        {
            ft_print_char((pointer - 10 + 'a'));
        }
    }
}

static int ft_pointer_length(void *ptr)
{
    int length;
    unsigned long long pointer;

    length = 0;
    pointer = (unsigned long long)ptr;
    while (pointer != 0)
    {
        length++;
        pointer /= 16;
    }
    return (length);
}
/* End of helpers for print_pointer*/
int ft_print_pointer(void *ptr)
{
    int print_length;
    unsigned long long pointer;

    pointer = (unsigned long long) ptr;
    print_length = 0;
    print_length += write(1, "0x", 2);
    if (pointer == 0)
    {
        print_length += write(1, "0", 1);
    }
    else
    {
        ft_put_pointer(pointer);
        print_length += ft_pointer_length(pointer);
    }
    return (print_length);
}
/* These functions are helpers for print_unsigned*/
static int ft_num_length(unsigned int n)
{
    int length;

    length = 0;
    while (n != 0)
    {
        length++;
        n /= 10;
    }
    return (length);
}

static char *ft_uitoa(unsigned int n)
{
    char *num;
    int length;

    length = ft_num_length(n);
    num = (char *)malloc(sizeof(char) * (len +1));
    if (!num)
    {
        return (NULL);
    }
    num[length] = '/0';
    while (n != 0)
    {
        num[length - 1] = n % 10 + '0';
        n /= 10;
        length--;
    }
    return (num);
}
/* End of helpers for print_unsigned*/
int ft_print_unsigned(unsigned int n)
{
    int print_length;
    char *num;

    print_length = 0;
    if (n == 0)
        print_length += write(1, "0", 1);
    else
    {
        num = ft_uitoa(n);
        print_length += ft_print_str(num);
        free(num);
    }
    return (print_length);
}

/* These functions are helpers for print_hex*/

static int ft_hex_length(unsigned int n)
{
    int length;

    length = 0;
    while (n != 0)
    {
        length++;
        n /= 16;
    }
    return (length);
}

static void ft_put_hex(unsigned int n, const char format)
{
    if (n >= 16)
    {
        ft_put_hex(n / 16, format);
        ft_put_hex(n % 16, format);
    }
    else
    {
        if (n <= 9)
            ft_print_char(n + '0');
        else
        {
            if (format == 'x')
                ft_print_char(n - 10 + 'a');
            if (format == 'X')
                ft_print_char(n - 10 + 'A');
        }
    }
}

/* End of helpers for print_hex*/

int ft_print_hex(unsigned int n, const char format)
{
    if (n == 0)
        return (write(1, "0", 1));
    else 
        ft_put_hex(n, format);
    return (ft_hex_length(n));
}