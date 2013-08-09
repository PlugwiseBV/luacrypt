#include <lua.h>
#include <lauxlib.h>

#include "luacrypt.h"
#include <crypt.h>
#include <string.h>

/***
Encrypt a password.
Not recommended for general encryption purposes.
@function crypt
@see crypt(3)
@string string
@string salt two-character string from [a-zA-Z0-9./]
@return encrypted string
*/
static int crypt_crypt(lua_State *L)
{
	const char *str, *salt;
	char *res;

	str = luaL_checkstring(L, 1);
	salt = luaL_checkstring(L, 2);
	if (strlen(salt) < 2)
		luaL_error(L, "not enough salt");

	res = crypt(str, salt);
	lua_pushstring(L, res);

	return 1;
}

static const struct luaL_reg luacrypt[] = {
    {"crypt", crypt_crypt},
    {NULL, NULL}    /* sentinel */
};

int luaopen_crypt(lua_State *L) {
    luaL_register(L, "crypt", luacrypt);
    return 1;
};
