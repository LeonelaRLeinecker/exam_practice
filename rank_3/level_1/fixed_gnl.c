#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return NULL;
}

void *ft_memcpy(void *dest, const void *src, int n)
{
	while (n-- > 0)
		((char*)dest)[n] = ((char*)src)[n];
	return dest;
}

int ft_strlen(char *s)
{
    int ret = 0;
    while (s && *s)
    {
        s++;
        ret++;
    }
    return (ret);
}

int str_append_mem(char **s1, char *s2, int size2)
{
    int size1 = ft_strlen(*s1);
    char *tmp = malloc(size2 + size1 + 1);
    if (!tmp)
        return 0;
    ft_memcpy(tmp, *s1, size1);
    ft_memcpy(tmp + size1, s2, size2);
    tmp[size1 + size2] = 0;
    free(*s1);
    *s1 = tmp;
    return 1;
}

int str_append_str(char **s1, char *s2)
{
    int size2 = ft_strlen(s2);
	return str_append_mem(s1, s2, size2);
}

void *ft_memmove(void *dest, const void *src, int n)
{
    if (dest > src)
        return ft_memcpy(dest, src, n);
    else if (dest == src)
        return dest;
    int i = ft_strlen((char*)src);
    int j = 0;
    while (j <= i)
    {
        ((char*)dest)[j] = ((char*)src)[j];
        j++;
    }
    return dest;
}

char *get_next_line(int fd)
{
    static char b[BUFFER_SIZE + 1] = "";
    char *ret = NULL;

    char *tmp = ft_strchr(b, '\n');
    while (!tmp)
    {
        if (!str_append_str(&ret, b))
            return NULL;
        int read_ret = read(fd, b, BUFFER_SIZE);
        if (read_ret == -1)
            return NULL;
        b[read_ret] = 0;

	if (read_ret == 0)
	{
		if (*ret)
			return (ret);
		free(ret);
		return NULL;
	}
	tmp = ft_strchr(b, '\n');
    }
    if (!str_append_mem(&ret, b, tmp - b + 1))
    {
	free(ret);
	return NULL;
    }
    ft_memmove(b, tmp + 1, ft_strlen(tmp + 1));
    return ret;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Uso: %s <arquivo_para_ler>\n", argv[0]);
        return 1;
    }

	// Abrimos argv[1]
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) // Cubrimos que sea negativo
    {
        perror("Error: no se puede abrir el archivo");
        return 1;
    }

    char *line;
    int count = 0;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Linea %d: %s", count + 1, line);
		free(line); // Podemos liberar directamente despues de generarla, aunque no se entrega main
		count++;
	}

    close(fd);
    return 0;
}
