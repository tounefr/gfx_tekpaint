/*
** bmp.c for  in /home/henon_t/gfx_tekpaint/srcs
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Sun Jan 24 21:03:36 2016 Thomas Henon
** Last update Tue Jan 26 19:58:02 2016 Thomas Henon
*/

#include "tekpaint.h"

t_bunny_pixelarray	*convert_to_pixelarray(int fd,
		       int width,
		       int height,
		       unsigned char bytes_per_pix)
{
  int			nbr_pixs;
  t_rgb_color		color;
  t_bunny_pixelarray	*img_buffer;
  unsigned int		i;
  unsigned int		i2;
  int			pixel;

  nbr_pixs = width * height;
  if (NULL == (img_buffer = bunny_new_pixelarray(width, height)))
    return (NULL);
  i = 0;
  while (i < nbr_pixs/width)
    {
      i2 = width;
      while (i2 > 0)
	{
	  pixel = nbr_pixs - (i * width) - i2--;
	  if (-1 == read(fd, &color, bytes_per_pix))
	    return (NULL);
	  set_rgb_pixel(img_buffer, pixel, &color);
	}
      read(fd, &color, width % 4);
      i++;
    }
  return (img_buffer);
}

void	paste_bmp(t_tekpaint *tekpaint, t_bunny_position *pos)
{
  pos->y -= tekpaint->tool.bmp_buffer_tmp->clipable.clip_height / 2;
  pos->x -= tekpaint->tool.bmp_buffer_tmp->clipable.clip_width / 2;
  blit_pixelarrays(tekpaint->workplan.buffer,
		   tekpaint->tool.bmp_buffer_tmp,
		   pos);
  bunny_delete_clipable(&(tekpaint->tool.bmp_buffer_tmp->clipable));
  tekpaint->tool.bmp_buffer_tmp = NULL;
  tekpaint->tool.current_tool = 0;
  my_putstr("Image copiée sur l'écran\n");
}

t_bunny_pixelarray	*load_bmp(char *file_path)
{
  int			fd;
  t_header_bmp		header_bmp;
  t_header_img_bmp	img_bmp;
  int			img_width;
  int			img_height;
  unsigned char		bytes_per_pix;

  if (-1 == (fd = open(file_path, O_RDONLY)))
    return (NULL);
  if (read(fd, &header_bmp, sizeof(t_header_bmp)) <= 0)
    return (NULL);
  if (read(fd, &img_bmp, sizeof(t_header_img_bmp)) <= 0)
    return (NULL);
  if (*((int*)&img_bmp.nbr_colors_palette) > 0)
    read(fd, NULL, 4);
  if (*((int*)&img_bmp.compression_method) != 0)
    {
      my_putstr("Impossible de charger une image compressé\n");
      return (NULL);
    }
  bytes_per_pix = *((int*)&img_bmp.bits_per_pixel) / 8;
  img_width = *((int*)&img_bmp.img_width);
  img_height = *((int*)&img_bmp.img_height);
  return (convert_to_pixelarray(fd, img_width, img_height, bytes_per_pix));
}
