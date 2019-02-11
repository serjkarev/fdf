
# define OVER_DOHUA 1000

void	brazenhaime(int *point1, int *point2, t_m *map)
{
	int		d_x = ABS(point2[0] - point1[0]);
	int		d_y = ABS(point2[1] - point1[1]);
	int		s_x = point1[0] < point2[0] ? 1 : -1;
	int		s_y = point1[1] < point2[1] ? 1 : -1;
	int		error = d_x - d_y;
	int 	error2;
	
	printf("########### IN BRAZ ##################\n");
	printf("point1 x = %d y = %d z = %d\n", point1[0], point1[1], point1[2]);
	printf("point2 x = %d y = %d z = %d\n", point2[0], point2[1], point2[2]);
	// if (point2[0] > 0 && point2[0] < WIN_SIZE_X && point2[1] > 0 && point2[1] < WIN_SIZE_Y)
	mlx_pixel_put(map->ptr, map->window, point2[0], point2[1], 255);
	int a = 0;
	while (point1[0] != point2[0] || point1[1] != point2[1])
	{
		a++;
		if (a > OVER_DOHUA)
		{
			printf("huihuihuihuihuihuihuihuihuihuihuihui\n");
			printf("point1 x = %d y = %d z = %d\n", point1[0], point1[1], point1[2]);
			printf("point2 x = %d y = %d z = %d\n", point2[0], point2[1], point2[2]);
			break;
		}
		// if (point1[0] > 0 && point1[0] < WIN_SIZE_X && point1[1] > 0 && point1[1] < WIN_SIZE_Y)
		mlx_pixel_put(map->ptr, map->window, point1[0], point1[1], 255);
		error2 = error * 2;
		if (error2 > -d_y)
		{
			error -= d_y;
			point1[0] += s_x;
		}
		if (error2 < d_x)
		{
			error += d_x;
			point1[1] += s_y;
		}
	}
	free(point1);
	free(point2);
}


void	DDA(int *point1, int *point2, t_m *map)
{
	int xr = ABS(point2[0] - point1[0]);
	int	yr = ABS(point2[1] - point1[1]);
	int	l;
	int dx;
	int dy;

	if (xr > yr)
		l = xr;
	else
		l = yr;
	int px=(point1[0]<<12)+(1<<11);
	int py=(point1[1]<<12)+(1<<11);
	int ex=(point2[0]<<12)+(1<<11);
	int ey=(point2[1]<<12)+(1<<11);
	if (l!=0)
	{
		dx = (ex-px) / l;
		dy = (ey-py) / l;
	}
	else
	{
		dx = 0;
		dy = 0;
	}
	for(int i=0;i<=l;i++)
	{
		mlx_pixel_put(map->ptr, map->window, px>>12, py>>12, 255);
		px+=dx;
		py+=dy;
	}
}


void	brazenhaime(int *point1, int *point2, t_m *map)
{
	int dx = (point2[0] - point1[0] >= 0 ? 1 : -1);
	int dy = (point2[1] - point1[1] >= 0 ? 1 : -1);
	int lengthX = abs(point2[0] - point1[0]);
	int lengthY = abs(point2[1] - point1[1]);
	int length = fmax(lengthX, lengthY);

	if (length == 0)
		mlx_pixel_put(map->ptr, map->window, point1[0], point1[1], 255);
	if (lengthY <= lengthX)
	{
		int x = point1[0];
		int y = point1[1];
		int d = -lengthX;

		length++;
		while(length--)
		{
			if (x <= WIN_SIZE_X && x >= 0 && y <= WIN_SIZE_Y && y >= 0)
				mlx_pixel_put(map->ptr, map->window, x, y, 255);
			x += dx;
			d += 2 * lengthY;
			if (d > 0) {
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		int x = point1[0];
		int y = point1[1];
		int d = - lengthY;

		length++;
		while(length--)
		{
			if (x <= WIN_SIZE_X && x >= 0 && y <= WIN_SIZE_Y && y >= 0)
				mlx_pixel_put(map->ptr, map->window, x, y, 255);
			y += dy;
			d += 2 * lengthX;
			if (d > 0) {
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
	free(point1);
	free(point2);
}


	int		point1[3] = {200, 200, 0};
	int		point2[8][3] = {{100, 100, 0},
	{200, 50, 0},
	{300, 100, 0},
	{100, 300, 0},
	{300, 300, 0},
	{200, 350, 0},
	{50, 200, 0},
	{350, 200, 0},
	};

	int i = 0;
	while (i <= 8)
	{
		mlx_pixel_put(map->ptr, map->window, point2[i][0], point2[i][1], 255);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		int		point1[3] = {200, 200, 0};
		// brazenhaime(point2[i++], point1, map);
		// brazenhaime(point1, point2[i++], map);
		// DDA(point1, point2[i++], map);
		brazenhaime_2(point1, point2[i++], map);
	}
