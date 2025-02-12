//usr/bin/cc $0 -L. -I. -lft -D USE_STD_PRINTF -o std.out || exit;\
//usr/bin/cc $0 -L. -I. -lft -o ft.out || exit;\
//$PWD/std.out > std.txt; echo "$?" > std.ret;\
//$PWD/ft.out > ft.txt; echo "$?" > ft.ret;\
echo "# Check output:";\
diff ft.txt std.txt && echo " - No difference found";\
echo "# Check return value:";\
diff ft.ret std.ret && echo " - No difference found";\
echo "# Content:";\
echo " - printf returns: $(cat std.ret)";\
echo '```';\
cat std.txt;\
echo '```';\
echo " - ft_printf returns: $(cat ft.ret)";\
echo '```';\
cat ft.txt;\
echo '```';\
exit;


#ifdef USE_STD_PRINTF
#include <stdio.h>
#define PRINTF(...) printf(__VA_ARGS__)
#else
#include "ft_printf.h"
#define PRINTF(...) ft_printf(__VA_ARGS__)
#endif

int main()
{
	char a = 'a';
	
	return PRINTF("%d\n", PRINTF("%s", "aiueo"));
}
