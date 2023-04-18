#include "Libft/src/ft_printf.h"
#include "Libft/src/libft.h"
#include "so_long.h"
 
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
    ft_printf(("W"));
  } 
  else
    return 1;
  return(0);

}
