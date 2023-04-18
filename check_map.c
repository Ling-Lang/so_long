#include "Libft/src/ft_printf.h"
#include "Libft/src/gnl/get_next_line_bonus.h"
#include "Libft/src/libft.h"
#include "so_long.h"
#include <sys/fcntl.h>
 
int ft_checkmap(int argc, char *argv[])
{
  if (argc <= 1)
    return 1;
  char *extension = ".ber";
  size_t extension_len = ft_strlen(extension);
  size_t filename_len = ft_strlen(argv[1]);

  if (filename_len >= extension_len && 
    !ft_strncmp(argv[1] + filename_len - extension_len, extension, filename_len))
  {
    ft_validate_map(argv[1]);
  } 
  else
    return 1;
  return 0;
}

void ft_validate_map(char *path)
{
  int fd;
  int i;
  char *map;

  i = 0;
  fd = open(path, O_RDONLY);
  map = get_next_line(fd);
  if (!map)
    return ;
  while (map[i] != '\0')
  {
    if(map[i] == '1')
      ft_printf("imaginary square\n");
    if(map[i] == '0')
      ft_printf("Space");
    i++;

  }
  
}
