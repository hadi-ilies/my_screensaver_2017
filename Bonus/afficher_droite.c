int draw_line(framebuffer_t *framebuffer, sfVector2i point_a, sfVector2i point_b, sfColor color)
{
	float A = 0;
        float B = 0;
	float C = 0;
	int x;
	int y;

	A = fabs((point_a.y - point_b.y) / (point_a.x - point_b.x));
	B = fabs((point_a.y - A * point_a.x));
	y =(float) A * x + B ;
	if(point_a.x >= point_b.x) {
		C = point_a.x;
		x = point_b.x;
	}
	else {
		C = point_b.x;
		x = point_a.x;
	}
	printf("%d\n", y);
	printf("%d\n", y);

	for(; x != C ; y++) {
		my_put_pixel(framebuffer, x,  y, color);
		x++;

	}
}
void my_put_pixel(framebuffer_t *buffer, unsigned int x, unsigned int y, sfColor color)
{

	buffer->pixels[(buffer->width * x + y ) * 4] = color.r;
	buffer->pixels[(buffer->width * x + y ) * 4 + 1] = color.g;
       	buffer->pixels[(buffer->width * x + y ) * 4 + 2] = color.b;
	buffer->pixels[(buffer->width * x + y ) * 4 + 3] = color.a;
}
sfVector2i sfVector_create( int a, int b)
{
	sfVector2i point;

	point.x = a;
	point.y = b;
}
// dans le main
int x = 100;
int y = 50;
int x2 = 400;
int y2 = 100;
framebuffer_t *buffer = framebuffer_create(width, height);
sfVector2i pointA = sfVector_create(x, y);
sfVector2i pointB = sfVector_create(x2,  y2);
