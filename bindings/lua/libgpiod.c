
    #include <lua.h>
    #include <luaxlib.h>
    #include <lualib.h>


/* 这里以lua5.1来示意 */
#define LUA_VERSION__   51
/*
 * 构造一个简单的函数
 */
static int hello(lua_State *L)
{
    char const *str;
    int age;
    str = luaL_checkstring(L, 1);   /* 传入的第一个参数是字符串（C风格的） */
    age = luaL_checkint(L, 2);      /* 传入的第二个参数是int型变量 */
    char tmp[512];
    snprintf(tmp, 512, "hello `%s`, your age is %d.", str, age);
    lua_pushstring(L, tmp);         /* 压入返回值 */
    return 1;                       /* 只有一个返回值 */
}
/* lua中函数名和c中函数映射 */
static const struct luaL_Reg funs[] = {
    {"say", hello},
    {NULL, NULL},
};
/*
 * lua中调用模块名为"hello"
 */
extern int luaopen_hello(lua_State *L)
{
    /* 在lua5.1之后注册函数变化了，LUA_VERSION__是我自己定义的宏:) */
#if (LUA_VERSION__ > 51)
    luaL_newlib(L, funs);
#else
    /* lua5.1 根据luaL_newlib函数，我们可以明白这里的"hello"参数并没有多大用 */
    luaL_register(L, "hello", funs);
#endif
    return 1;
}