#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void    printfmap(int **map, int n)
{
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", map[j][i]);
        }
        printf("\n");
    }
}

int colup_check(int **map, int row, int col ,int *colup, int max_number)
{
    int height_min = 0;
    int height_max = 0;
    int max = 0;

    // 0 0 3 4  0 == 0
    for (int k = 0; k < max_number; k++)
    {
        if (map[k][col] == max)
            height_max++;
        else if (map[k][col] > max)
        {
            max = map[k][col];
            height_max++;
            height_min++;
        }
    }
    //if (is_zero(map, col, 0))
    //    if (height == colup[col])
    //        return (1);
    if (height_min <=  colup[col] && colup[col] <= height_max)
        return (1);
    return (0);
}


int coldown_check(int **map, int row, int col ,int *coldown, int n2)
{
    int height_min = 0;
    int height_max = 0;
    int max = 0;

    for (int k = n2 -1; k >= 0; k--)
    {
        // printf("%d\n", map[row][k]);
        if (map[k][col] == max)
            height_max++;
        else if (map[k][col] > max)
        {
            height_max++;
            height_min++;
            max = map[k][col];
        }
    }
    // printf("up:%d %d\n", height, colup[i]);
    //if (is_zero(map, col, 0))
    //    if (height == coldown[col])
    //        return (1);
    if (height_min <=  coldown[col] && coldown[col] <= height_max)
        return (1);
    return (0);
}


int rowleft_check(int **map, int row, int col ,int *rowleft, int max_number)
{
    int height_min = 0;
    int height_max = 0;
    int max = 0;

    for (int k = 0; k < max_number; k++)
    {
        if (map[row][k] == max)
            height_max++;
        else if (map[row][k] > max)
        {
            height_max++;
            height_min++;
            max = map[row][k];
        }
    }
    // printf("up:%d %d\n", height, colup[i]);
    //if (is_zero(map, row, 1))
    //    if (height == rowleft[row])
    //        return (1);
    if (height_min <= rowleft[row] && rowleft[row] <= height_max)
        return (1);
    return (0);
}


int rowright_check(int **map, int row, int col ,int *rowright, int n2)
{
    int height_min = 0;
    int height_max = 0;
    int max = 0;

    for (int k = n2 - 1; k >= 0; k--)
    {
        if (map[row][k] == max)
            height_max++;
        else if (map[row][k] > max)
        {
            height_max++;
            height_min++;
            max = map[row][k];
        }
    }
    // printf("up:%d %d\n", height, colup[i]);
    //if (is_zero(map, row, 1))
    //    if (height == rowright[row])
    //        return (1);
    if (height_min <=  rowright[row] && rowright[row] <= height_max)
        return (1);
    return (0);
}


int valid_check(int **map, int row, int col, int *colup, int *coldown, int *rowleft, int *rowright, int n2)
{
    if (colup_check(map, row , col, colup, n2) && coldown_check(map, row , col, coldown, n2) && rowleft_check(map, row , col, rowleft, n2) && rowright_check(map, row , col, rowright, n2))
    {   
        return (1);
    }
    return (0);
}
int col_row_check(int n, int **map, int row, int col, int n2)
{
    for (int i = 0; i < n2; i++)
    {
        if (map[row][i] == n ||  map[i][col] == n)
            return (0);
    }
    return (1);
}

int    rush(int **map, int n, int col, int *colup, int *coldown, int *rowleft, int *rowright, int n2)
{
    if (n == 0)
        return (1);
    if (col == n2)
        return (rush(map, n - 1, 0, colup, coldown, rowleft, rowright, n2));
    for (int row = 0; row < n2; row++)
    {
        if (!map[row][col] && col_row_check(n, map, row, col, n2))
        {
            map[row][col] = n;
            if (valid_check(map, row, col, colup, coldown, rowleft, rowright, n2))
                if (rush(map, n, col + 1, colup, coldown, rowleft, rowright, n2))
                    return (1);
            map[row][col] = 0;
        }
    }
    return (0);
}
void	ft_bzero(void *dest, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = dest;
	i = 0;
	while (i < n)
		p[i++] = 0;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s1;
	size_t			t_size;

	t_size = size * nmemb;
	s1 = malloc(t_size);
	if (s1 == 0)
		return (0);
	ft_bzero(s1, t_size);
	return ((void *)s1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int main(int arg, char **args)
{
    int i  = ft_strlen(args[1]);
    int n = (i + 1) / 8; 

    int **map = (int **)ft_calloc(sizeof(int *), n);
    for (int j = 0; j < n;++j)
    {
        map[j] = (int *)ft_calloc(sizeof(int), n);
    }
    int *colup = ft_calloc(sizeof(int), n);
    int *coldown = ft_calloc(sizeof(int), n);
    int *rowleft = ft_calloc(sizeof(int), n);
    int *rowright = ft_calloc(sizeof(int), n);
    int k;
  //  for (int j = 0; j <= i; j += 2)
 //   {
        int j = -2;
        k = 0;
        while (k < n) '3' 51
			// 3, '3'(51) - '0'
            colup[k++] = args[1][j+=2] - '0';
        k = 0;
        while (k < n)
            coldown[k++] = args[1][j+=2]- '0';
        k = 0;
        while (k < n)
            rowleft[k++] = args[1][j+=2]- '0';
        k = 0;
        while (k < n)
            rowright[k++] = args[1][j+=2]- '0';
   // }
//    for (int i = 0; i < n; i++)
//     printf("%d ", colup[i]);
//    for (int i = 0; i < n; i++)
//     printf("%d ", coldown[i]);
//    for (int i = 0; i < n; i++)
//     printf("%d ", rowleft[i]);
//    for (int i = 0; i < n; i++)
//     printf("%d ", rowright[i]);
    // int **map;
    if (!rush(map, n, 0 , colup, coldown, rowleft, rowright, n))
	{
        printf("invalid input!!\n");
		printfmap(map, n);
	}
    // printf("ok\n");
    printfmap(map, n);
    // return (0);
}