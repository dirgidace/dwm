/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "waterfox-g4"

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 5;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[] = {
        "SauceCodePro Mono:pixelsize=14:style=bold",
        "SauceCodePro Nerd Font Mono:pixelsize=16:style=bold",
 };
static const char dmenufont[]       = "SauceCodePro Mono:pixelsize=14:style=bold";

/* Custom Colors */
static const char col_bar_bg[]      = "#120f14"; /* dark purple */
static const char col_bar_fg[]      = "#ffffff"; /* white */

static const char col_pure_white[]  = "#ffffff"; /* black   */
static const char col_red[]         = "#ef2c47"; /* red     */
static const char col_green[]       = "#a8d84b"; /* green   */
static const char col_yellow[]      = "#ff9902"; /* yellow  */
static const char col_blue[]        = "#06b6ef"; /* blue    */
static const char col_magenta[]     = "#cf5a98"; /* magenta */
static const char col_cyan_custom[] = "#4fe3c8"; /* cyan    */
static const char col_white[]       = "#fafafa"; /* white   */

static const char col_gray1[]       = "#120f14"; /* dark purple */
static const char col_gray2[]       = "#ffffff"; /* black   */
static const char col_gray3[]       = "#ffffff"; /* black   */
static const char col_gray4[]       = "#ffffff"; /* black   */
static const char col_cyan[]        = "#c2304b"; /* hot pink*/

static const char col_selected_f[]  = "#c2304b"; /* hot pink*/
static const char col_selected[]    = "#ffffff"; /* white */
static const char col_unselected[]  = "#777777"; /* gray */


static const char *colors[][4]      = {
	/*               fg         bg         border     float */
	[SchemeNorm] = { col_bar_fg, col_bar_bg, col_unselected, col_unselected },
	[SchemeSel] =  { col_bar_fg, col_bar_bg,  col_selected, col_selected_f },

		/*					         fg           bg              border   */
	[SchemeWarn] =	 { col_yellow, 	col_bar_bg, 	col_bar_bg }, // \x03
	[SchemeUrgent]=	 { col_white, 	col_red,    	col_bar_bg }, // \x04
	[SchemeCol1]= { col_red, 	col_bar_bg,    	col_bar_bg }, // \x05
	[SchemeCol2]= { col_green, 	col_bar_bg,    	col_bar_bg }, // \x06
	[SchemeCol3]= { col_blue, 	col_bar_bg,    	col_bar_bg }, // \x07
	[SchemeCol4]= { col_magenta, 	col_bar_bg,    	col_bar_bg }, // \x08
	[SchemeCol5]= { col_cyan_custom, 	col_bar_bg,    	col_bar_bg }, // \x09
	[SchemeCol6]= { col_magenta, 	col_bar_bg,    	col_bar_bg }, // \x0a
	[SchemeCol7]= { col_cyan_custom, 	col_bar_bg,    	col_bar_bg }, // \x0b
	[SchemeCol8]= { col_red, 	col_bar_bg,    	col_bar_bg }, // \x0c
	[SchemeCol9]= { col_red, 	col_bar_bg,    	col_bar_bg }, // \x0d
};

/* tagging */
/* 1: Terminal, 2: Code, 3: Files, 4: Files, 5: Spotify, 6: Projector, 7: Discord, 8: Firefox, 9: Firefox*/
static const char *tags[] =    { "", "", "", "", "", "󰐮", "󰙯", "", "" };
static const char *tagsalt[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const char *defaulttagapps[] = { TERMINAL, "vscodium", NULL, NULL, "spotify-launcher", NULL, "discord", "waterfox-g4", "waterfox-g4" };
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

static const char *tagsel[][2][2] = {
	/*      norm                          sel       */
	/*  fg          bg              fg          bg  */
	{ { col_cyan, 			col_gray1 }, { col_bar_bg, col_cyan } },
	{ { col_cyan,			col_gray1 }, { col_bar_bg, col_cyan } },
	{ { col_cyan_custom,		col_gray1 }, { col_bar_bg, col_cyan_custom } },
	{ { col_cyan_custom,		col_gray1 }, { col_bar_bg, col_cyan_custom } },
	{ { col_green,			col_gray1 }, { col_bar_bg, col_green } },
	{ { col_white,   		col_gray1 }, { col_bar_bg, col_white } },
	{ { col_blue,  			col_gray1 }, { col_bar_bg, col_blue } },
	{ { col_yellow,			col_gray1 }, { col_bar_bg, col_yellow } },
	{ { col_yellow, 		col_gray1 }, { col_bar_bg, col_yellow } },
};




static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask 	isfloating  isterminal      noswallow	monitor */
	{ TERMCLASS,	NULL,       NULL,       	    0,            0,           1,         0,        -1 },
	{ NULL,		NULL,       "ncpamixer",       	    0,            1,           1,         0,        -1 },
	{ NULL,		NULL,       "nmtui",       	    0,            1,           1,         0,        -1 },
	{ NULL,		NULL,       "cal",       	    0,            1,           1,         0,        -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { TERMINAL, NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_w,      spawndefault,   {0} },
	{ MODKEY,                       XK_b,      togglebar,      {0} },

	{ MODKEY,	    		XK_f,	   spawn,	   	   SHCMD("feh --recursive --bg-fill --randomize /media/pictures/Wallpapers/*")},

	{ MODKEY,	     		XK_Up,	   spawn,	   	   SHCMD("amixer sset Master playback 5%+;pkill -RTMIN+8 dwmblocks")},
	{ MODKEY,	     		XK_Down,   spawn,	   	   SHCMD("amixer sset Master playback 5%-;pkill -RTMIN+8 dwmblocks")},
	{ MODKEY,			XK_m,	   spawn,	   	   SHCMD("amixer -D pulse set Master 1+ toggle;pkill -RTMIN+8 dwmblocks")},
	{ MODKEY|ShiftMask,		XK_m,  	   spawn,	   	   SHCMD("st ncpamixer")},
	{ MODKEY,			XK_p,  	   spawn,	   	   SHCMD("playerctl -p spotify play-pause")},

	{ MODKEY,	 		XK_Right,  spawn,	   	   SHCMD("sudo light -A 25")},
	{ MODKEY,	     		XK_Left,   spawn,	   	   SHCMD("sudo light -U 25")},

	{ MODKEY,	     		XK_a,      spawn,	   	   SHCMD("autorandr -c")},
	{ MODKEY|ShiftMask,     	XK_n,      spawn,	   	   SHCMD("st nmtui")},

	{ 0,	     			XK_Print,  spawn,	   	   SHCMD("flameshot gui")},
	{ MODKEY,	     		XK_e,  	   spawn,	   	   SHCMD("st lfrun")},

	{ MODKEY,	     		XK_c,  	   spawn,	   	   SHCMD("st cal --color -3")},
	{ MODKEY|ShiftMask,  		XK_c,  	   spawn,	   	   SHCMD("st cal --color -y")},

	{ MODKEY,	     		XK_F4,     spawn,	   	   SHCMD("sudo shutdown -h 0")},
	{ MODKEY,	     		XK_F5,     spawn,	   	   SHCMD("sudo reboot")},

	{ MODKEY,                       XK_s,      togglesticky,   {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },

	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	// { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	// { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	// { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	// { MODKEY,                       XK_c,      setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	// { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	// { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },

	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

	// { MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY,                       XK_n,      togglealttag,   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      quit,           {1} }, 
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

