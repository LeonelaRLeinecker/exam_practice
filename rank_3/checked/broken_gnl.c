#include "get_next_line.h"

//CAMBIAR LOS SIZE_T POR INTS PARA EVITAR OVERFLOWS CON NUMEROS NEGATIVOS

char *ft_strchr(char *s, int c)
{
  int i = 0;
  while(s[i] && s[i] != c) //añadir la comprobacion de que exista s[i]
    i++;
  if (s[i] == c)
    return s + i;
  else
    return NULL;
}

void *ft_memcpy(void *dest, const void *src, int n)
{
  while(n-- > 0)
    ((char *)dest)[n] = ((char *)src)[n]; //cambiar la iteracion de n y la copia dest[n] y src[n] en lugar de [n - 1]
  return dest;
}

int ft_strlen(char *s)
{
  int res = 0;
  while (s && *s) //comprobar la existencia de s
  {
    s++;
    res++;
  }
  return res;
}

int str_append_mem(char **s1, char *s2, int size2)
{
  int size1 = ft_strlen(*s1);
  char *tmp = malloc(size2 + size1 + 1);
  if (!tmp)
    return 0;
  ft_memcpy(tmp, *s1, size1);
  ft_memcpy(tmp + size1, s2, size2);
  tmp[size1 + size2] = '\0';
  free(*s1);
  *s1 = tmp;
  return 1; 
}

int str_append_str(char **s1, char *s2)
{
  return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void  tmp = ft_strchr(b, '\n');*src, int n)
{
  if (dest > src)
    return ft_memcpy(dest, src, n);
  else if (dest == src)
    return dest;
  int j = ft_strlen((char *)src); //igualar el len de src a j una variable que declaramos ahi, y ajustar i para que itere de 0 a j copiando de atras hacia adelante
  int i = 0; 
  while (i </<= j) // cambiamos i >= 0 por i < j o i <= j
  {
    ((char *)dest)[i] = ((char *)src)[i];
    i++; // cambiamos i-- por i++
  }
  return dest;
}

char *get_next_line(int fd)
{
  static char b[BUFFER_SIZE + 1] = "";
  char *ret = NULL;
  char *tmp = ft_strchr(b, '\n');
  while(!tmp)
  {
    if (!str_append_str(&ret, b))
      return (NULL);
    int read_ret = read(fd, b, BUFFER_SIZE);
    if (read_ret == -1)
      return (NULL);
    b[read_ret] = 0;
    if (read_ret == 0)  // añadir la condicion de fin de lectura, 
	{
		if (*ret)		 //si hay algo que devolver para el momento de final de lectura lo devolvemos
			 return(ret);
		free(ret);		//si no lo hay liberamos y retornamos NULL
		return(NULL);
	}
    tmp = ft_strchr(b, '\n');		//integramos la busqueda de \n dentro del bucle
  }
  if (!str_append_mem(&ret, b, tmp - b + 1))
  {
    free(ret);
    return NULL;
  }
  ft_memmove(b, tmp + 1, ft_strlen(tmp + 1)); // una ultima llamada a memmove sumando a tmp + 1 para updatear sin añadir el salto de lina
  return ret;
}
