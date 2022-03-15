#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    if(str == NULL) 
    return my_putstr("(null)");
    
    int i = 0;
    while(str[i]!= '\0')
    {
        my_putchar(str[i]);
        i++;
    }
    return i;
}

void my_putnbr(int num)
{
   if (num < 0)
    {
      my_putchar('-');
      num = num * -1;
    }
   
   if (num >= 10) 
    {
      my_putnbr(num / 10);
      my_putnbr(num % 10);
    } 
   else
  my_putchar(num + 48);
}

void my_putoctal(unsigned int n)
{
    int result = 0;
    int i = 1;

    while (n != 0) 
    {
        result += (n % 8) * i;
        n = n / 8;
        i = i * 10;
    }
  my_putnbr(result);
}

void my_put_unsigned_int(unsigned int n)
{
  if (n >= 10) 
  {
    my_put_unsigned_int(n / 10);
    my_put_unsigned_int(n % 10);
  } 
 else
    my_putchar(48 + n);
}

void my_put_hex(unsigned int n)
{
  int result;
  if (n >= 16)
    {
      result = n % 16;
      n = n / 16;
      my_put_hex(n);
    }
  else if (n > 0)
    {
      result = n % 16;
      n = n / 16;
    }
  if (result > 9)
    my_putchar(result + 87);
  else
    my_putchar(result + 48);
}

void my_MemCpy(void *dest, void *src, int n)
{
   char *csrc = (char *)src;
   char *cdest = (char *)dest;
  
   for (int i=0; i<n; i++)
       cdest[i] = csrc[i];
}

void my_put_pointer(void* p)
{
  char buf[sizeof(p)];

  my_MemCpy(buf, &p, sizeof(p));

  for (int i = sizeof(p) - 1; i >= 0; i--) 
  {
    char hi = (buf[i] >> 4) & 0xf; 
    char lo = buf[i] & 0xf;        
    char tmp[2] = {hi, lo};

    tmp[0] += hi < 10 ? '0' : 'a' - 10;
    tmp[1] += lo < 10 ? '0' : 'a' - 10;

    write(1, tmp, 2);
  }
}

int my_printf(char *format, ...)
{
    va_list args;
    va_start(args, format);
    char output;

   while ((output = *format) != '\0') 
    {
      format++;
        if (output != '%') 
        {
            my_putchar(output);
            continue;
        }
        switch (*format++) 
        {
         case 'c':
            my_putchar(va_arg(args, int));
            break;
         case 's':
            my_putstr(va_arg(args, char*));
            break;
         case 'd':
         case 'i':
            my_putnbr(va_arg(args, int));
            break;
         case 'o':
            my_putoctal(va_arg(args, unsigned int));
            break;
         case 'u':
            my_put_unsigned_int(va_arg(args, unsigned int));
            break;
         case 'x':
            my_put_hex(va_arg(args, unsigned int));
            break;
         case 'p':
            my_put_pointer(va_arg(args, void*));
            break;
         case '%':
            my_putchar('%');
            break;   
        }
    }
    va_end(args);

 return 0;
}

int main(void) 
{
my_printf("space for testing");

return 0;
}
