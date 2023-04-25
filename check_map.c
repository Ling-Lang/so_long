#include "Libft/src/ft_printf.h"
#include "Libft/src/gnl/get_next_line_bonus.h"
#include "Libft/src/libft.h"
#include "so_long.h"
#include <sys/fcntl.h>
 
int ft_checkmap(int argc, char *argv[])
{
  // int width;
  // int height;
  
  char *extension = ".ber";
  size_t extension_len = ft_strlen(extension);
  size_t filename_len = ft_strlen(argv[1]);
  if (argc <= 1)
    return 1;

  // height = 0;
  // width = 0;
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
  int line_length;
  char *map;
  char map_segment;
  int i;

  fd = open(path, O_RDONLY);
  map = get_next_line(fd);
  if (!map)
    return ;
  while (map)
  {
    line_length = ft_strlen(map);
    i = 0;
    while (i < line_length)
    {
      map_segment = map[i];
      // ft_printf("%c", map_segment);
      ft_draw_map(map_segment);
      i++;
    }
    ft_printf("\n");
    free(map);
    map = get_next_line(fd);
  }
}

// void ft_draw_map_lines(char *map)
// {
//     int i = 0;
//     char map_segment;
//     int line_length = ft_strlen(map);

//     while (i < line_length)
//     {
//         map_segment = map[i];
//         // ft_printf("%c", map_segment);
//         ft_draw_map(map_segment);
//         i++;
//     }
//     ft_printf("\n");
// }

// TODO Fix ft_read_map();
// static void ft_read_map(char *path, int *height, int *width)
// {
//     int fd;
//     char *map;

//     fd = open(path, O_RDONLY);
//     map = get_next_line(fd);

//     *height = 0;
//     *width = 0;

//     if (!map)
//         return;
//     while (map)
//     {
//         if (*height == 0)
//         {
//             *width = ft_strlen(map);
//         }
//         If (is_map_valid())
//         ft_draw_map_lines(map);
//         free(map);
//         map = get_next_line(fd);
//         (*height)++;
//     }
//     close(fd);
// }

void  ft_draw_map(char map)
{
  if(map == '1')
  {
    ft_printf("Imaginary Wall");
  }
  if(map == 'E')
    ft_printf("Imaginary exit");
  if (map == '0')
    ft_printf("Imaginary space");
  if (map == 'P')
    ft_printf("Imaginary player start");
  if(map == 'C')
    ft_printf("Imaginary collectible");
}


bool is_map_valid(char **map, int height, int width)
{
    int player_count = 0;
    int collectible_count = 0;
    int exit_count = 0;

    int row = 0;
    while (row < height)
     {
        int col = 0;
        while (col < width)
         {
            char current = map[row][col];
            if (row == 0 || row == height - 1 || col == 0 || col == width - 1) 
            {
                if (current != '1') 
                {
                    printf("Error: Map must be closed/surrounded by walls.\n");
                    return false;
                }
            } else 
            {
                if (current == 'P') 
                {
                    player_count++;
                } else if (current == 'C')
                 {
                    collectible_count++;
                } 
                else 
                if (current == 'E')
                 {
                    exit_count++;
                }
                 else
                  if (current != '0' && current != '1')
                 {
                    printf("Error: Invalid character in map.\n");
                    return false;
                }
            }
            col++;
        }
        row++;
    }
    if (player_count != 1 || exit_count != 1 || collectible_count < 1) {
        printf("Error: Map must contain 1 player, 1 exit, and at least 1 collectible.\n");
        return false;
    }
    return true;
}
