/*
** init2.c for  in /home/henon_t/gfx_tekpaint/srcs
**
** Made by Thomas Henon
** Login   <henon_t@epitech.net>
**
** Started on  Sun Jan 24 20:31:28 2016 Thomas Henon
** Last update Thu Jan 28 20:39:19 2016 Thomas HENON
*/

#include "tekpaint.h"

char		init_music()
{
  t_bunny_music	*music;

  if (NULL == (music = bunny_load_music(MUSIC_PATH)))
    return (0);
  bunny_sound_loop((t_bunny_sound*)music, true);
  bunny_sound_play((t_bunny_sound*)music);
  return (1);
}

char			init_logo(t_toolbar *toolbar)
{
  t_bunny_position	pos;
  t_bunny_pixelarray	*buffer;

  if (NULL == (buffer = load_bmp(LOGO_PATH)))
    return (0);
  my_putstr("Logo chargé !\n");
  pos.x = 0;
  pos.y = 0;
  blit_pixelarrays(toolbar->buffer, buffer, &pos);
  return (1);
}

char	free_window(t_tekpaint *tekpaint)
{
  bunny_free(tekpaint->toolbar.buttons);
  if (tekpaint->window.background)
    bunny_delete_clipable(&tekpaint->window.background->clipable);
  if (tekpaint->workplan.buffer)
    bunny_delete_clipable(&tekpaint->workplan.buffer->clipable);
  if (tekpaint->tool.font_buffer)
    bunny_delete_clipable(&tekpaint->tool.font_buffer->clipable);
  my_putstr("Window freed\n");
}
