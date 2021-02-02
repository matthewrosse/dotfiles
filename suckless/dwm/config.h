/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>
/* appearance */
static const unsigned int borderpx = 1; /* border pixel of windows */
static const unsigned int snap = 32;    /* snap pixel */
static const unsigned int gappih = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv = 10;  /* vert inner gap between windows */
static const unsigned int gappoh =
    10; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov =
    30; /* vert outer gap between windows and screen edge */
static const int smartgaps =
    0; /* 1 means no outer gap when there is only one window */
static const char autostartblocksh[] = "autostart_blocking.sh";
static const char autostartsh[] = "autostart.sh";
static const char dwmdir[] = "dwm";
static const char localshare[] = ".local/share";
static const int showbar = 1; /* 0 means no bar */
static const int topbar = 1;  /* 0 means bottom bar */
static const int vertpad = 0; /* vertical padding of bar */
static const int sidepad = 0; /* horizontal padding of bar */
static const int focusonwheel = 0;
static int floatposgrid_x = 5;                /* float grid columns */
static int floatposgrid_y = 5;                /* float grid rows */
static const unsigned int systrayspacing = 2; /* systray spacing */
static const int showsystray = 1;             /* 0 means no systray */
/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype = INDICATOR_NONE;
static int floatindicatortype = INDICATOR_TOP_LEFT_SQUARE;
static const char font[] = "Mononoki Nerd Font 12";
static const char dmenufont[] = "Hack Nerd Font:size=12";

static char c000000[] = "#000000"; // placeholder value
// wczesniej bylo #bbbbbb
static char normfgcolor[] = "#bbbbbb"; // bar font color
static char normbgcolor[] = "#222222";
static char normbordercolor[] = "#444444";
static char normfloatcolor[] = "#db8fd9";

static char selfgcolor[] = "#eeeeee";
static char selbgcolor[] = "#924441";
static char selbordercolor[] = "#005577";
static char selfloatcolor[] = "#005577";

static char titlenormfgcolor[] = "#bbbbbb";
static char titlenormbgcolor[] = "#222222";
static char titlenormbordercolor[] = "#444444";
static char titlenormfloatcolor[] = "#db8fd9";

static char titleselfgcolor[] = "#eeeeee";
static char titleselbgcolor[] = "#005577";
static char titleselbordercolor[] = "#005577";
static char titleselfloatcolor[] = "#005577";

static char tagsnormfgcolor[] = "#bbbbbb";
static char tagsnormbgcolor[] = "#222222";
static char tagsnormbordercolor[] = "#444444";
static char tagsnormfloatcolor[] = "#db8fd9";

static char tagsselfgcolor[] = "#eeeeee";
static char tagsselbgcolor[] = "#924441"; // tag's color
static char tagsselbordercolor[] = "#005577";
static char tagsselfloatcolor[] = "#005577";

static char hidfgcolor[] = "#005577";
static char hidbgcolor[] = "#222222";
static char hidbordercolor[] = "#005577";
static char hidfloatcolor[] = "#f76e0c";

static char urgfgcolor[] = "#bbbbbb";
static char urgbgcolor[] = "#222222";
static char urgbordercolor[] = "#ff0000";
static char urgfloatcolor[] = "#db8fd9";

static char normTTBbgcolor[] = "#330000";
static char normLTRbgcolor[] = "#330033";
static char normMONObgcolor[] = "#000033";
static char normGRIDbgcolor[] = "#003300";
static char normGRD1bgcolor[] = "#003300";
static char normGRD2bgcolor[] = "#003300";
static char normGRDMbgcolor[] = "#506600";
static char normHGRDbgcolor[] = "#b96600";
static char normDWDLbgcolor[] = "#003333";
static char normSPRLbgcolor[] = "#333300";
static char normfloatbgcolor[] = "#115577";
static char actTTBbgcolor[] = "#440000";
static char actLTRbgcolor[] = "#440044";
static char actMONObgcolor[] = "#000044";
static char actGRIDbgcolor[] = "#004400";
static char actGRD1bgcolor[] = "#004400";
static char actGRD2bgcolor[] = "#004400";
static char actGRDMbgcolor[] = "#507711";
static char actHGRDbgcolor[] = "#b97711";
static char actDWDLbgcolor[] = "#004444";
static char actSPRLbgcolor[] = "#444400";
static char actfloatbgcolor[] = "#116688";
static char selTTBbgcolor[] = "#550000";
static char selLTRbgcolor[] = "#550055";
static char selMONObgcolor[] = "#212171";
static char selGRIDbgcolor[] = "#005500";
static char selGRD1bgcolor[] = "#005500";
static char selGRD2bgcolor[] = "#005500";
static char selGRDMbgcolor[] = "#508822";
static char selHGRDbgcolor[] = "#b98822";
static char selDWDLbgcolor[] = "#005555";
static char selSPRLbgcolor[] = "#555500";
static char selfloatbgcolor[] = "#117799";
// 0xd0
static const unsigned int baralpha = 130;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
    /*                       fg      bg        border     */
    [SchemeNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeTitleNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeTitleSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsNorm] = {OPAQUE, baralpha, borderalpha},
    [SchemeTagsSel] = {OPAQUE, baralpha, borderalpha},
    [SchemeHid] = {OPAQUE, baralpha, borderalpha},
    [SchemeUrg] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActTTB] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActLTR] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActMONO] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActGRID] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActGRD1] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActGRD2] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActGRDM] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActHGRD] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActDWDL] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActSPRL] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexActFloat] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaTTB] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaLTR] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaMONO] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaGRID] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaGRD1] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaGRD2] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaGRDM] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaHGRD] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaDWDL] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaSPRL] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexInaFloat] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelTTB] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelLTR] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelMONO] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelGRID] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelGRD1] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelGRD2] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelGRDM] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelHGRD] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelDWDL] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelSPRL] = {OPAQUE, baralpha, borderalpha},
    [SchemeFlexSelFloat] = {OPAQUE, baralpha, borderalpha},
};

static char *colors[][ColCount] = {
    /*                       fg                bg                border float
     */
    [SchemeNorm] = {normfgcolor, normbgcolor, normbordercolor, normfloatcolor},
    [SchemeSel] = {selfgcolor, selbgcolor, selbordercolor, selfloatcolor},
    [SchemeTitleNorm] = {titlenormfgcolor, titlenormbgcolor,
                         titlenormbordercolor, titlenormfloatcolor},
    [SchemeTitleSel] = {titleselfgcolor, titleselbgcolor, titleselbordercolor,
                        titleselfloatcolor},
    [SchemeTagsNorm] = {tagsnormfgcolor, tagsnormbgcolor, tagsnormbordercolor,
                        tagsnormfloatcolor},
    [SchemeTagsSel] = {tagsselfgcolor, tagsselbgcolor, tagsselbordercolor,
                       tagsselfloatcolor},
    [SchemeHid] = {hidfgcolor, hidbgcolor, hidbordercolor, hidfloatcolor},
    [SchemeUrg] = {urgfgcolor, urgbgcolor, urgbordercolor, urgfloatcolor},
    [SchemeFlexActTTB] = {titleselfgcolor, actTTBbgcolor, actTTBbgcolor,
                          c000000},
    [SchemeFlexActLTR] = {titleselfgcolor, actLTRbgcolor, actLTRbgcolor,
                          c000000},
    [SchemeFlexActMONO] = {titleselfgcolor, actMONObgcolor, actMONObgcolor,
                           c000000},
    [SchemeFlexActGRID] = {titleselfgcolor, actGRIDbgcolor, actGRIDbgcolor,
                           c000000},
    [SchemeFlexActGRD1] = {titleselfgcolor, actGRD1bgcolor, actGRD1bgcolor,
                           c000000},
    [SchemeFlexActGRD2] = {titleselfgcolor, actGRD2bgcolor, actGRD2bgcolor,
                           c000000},
    [SchemeFlexActGRDM] = {titleselfgcolor, actGRDMbgcolor, actGRDMbgcolor,
                           c000000},
    [SchemeFlexActHGRD] = {titleselfgcolor, actHGRDbgcolor, actHGRDbgcolor,
                           c000000},
    [SchemeFlexActDWDL] = {titleselfgcolor, actDWDLbgcolor, actDWDLbgcolor,
                           c000000},
    [SchemeFlexActSPRL] = {titleselfgcolor, actSPRLbgcolor, actSPRLbgcolor,
                           c000000},
    [SchemeFlexActFloat] = {titleselfgcolor, actfloatbgcolor, actfloatbgcolor,
                            c000000},
    [SchemeFlexInaTTB] = {titlenormfgcolor, normTTBbgcolor, normTTBbgcolor,
                          c000000},
    [SchemeFlexInaLTR] = {titlenormfgcolor, normLTRbgcolor, normLTRbgcolor,
                          c000000},
    [SchemeFlexInaMONO] = {titlenormfgcolor, normMONObgcolor, normMONObgcolor,
                           c000000},
    [SchemeFlexInaGRID] = {titlenormfgcolor, normGRIDbgcolor, normGRIDbgcolor,
                           c000000},
    [SchemeFlexInaGRD1] = {titlenormfgcolor, normGRD1bgcolor, normGRD1bgcolor,
                           c000000},
    [SchemeFlexInaGRD2] = {titlenormfgcolor, normGRD2bgcolor, normGRD2bgcolor,
                           c000000},
    [SchemeFlexInaGRDM] = {titlenormfgcolor, normGRDMbgcolor, normGRDMbgcolor,
                           c000000},
    [SchemeFlexInaHGRD] = {titlenormfgcolor, normHGRDbgcolor, normHGRDbgcolor,
                           c000000},
    [SchemeFlexInaDWDL] = {titlenormfgcolor, normDWDLbgcolor, normDWDLbgcolor,
                           c000000},
    [SchemeFlexInaSPRL] = {titlenormfgcolor, normSPRLbgcolor, normSPRLbgcolor,
                           c000000},
    [SchemeFlexInaFloat] = {titlenormfgcolor, normfloatbgcolor,
                            normfloatbgcolor, c000000},
    [SchemeFlexSelTTB] = {titleselfgcolor, selTTBbgcolor, selTTBbgcolor,
                          c000000},
    [SchemeFlexSelLTR] = {titleselfgcolor, selLTRbgcolor, selLTRbgcolor,
                          c000000},
    [SchemeFlexSelMONO] = {titleselfgcolor, selMONObgcolor, selMONObgcolor,
                           c000000},
    [SchemeFlexSelGRID] = {titleselfgcolor, selGRIDbgcolor, selGRIDbgcolor,
                           c000000},
    [SchemeFlexSelGRD1] = {titleselfgcolor, selGRD1bgcolor, selGRD1bgcolor,
                           c000000},
    [SchemeFlexSelGRD2] = {titleselfgcolor, selGRD2bgcolor, selGRD2bgcolor,
                           c000000},
    [SchemeFlexSelGRDM] = {titleselfgcolor, selGRDMbgcolor, selGRDMbgcolor,
                           c000000},
    [SchemeFlexSelHGRD] = {titleselfgcolor, selHGRDbgcolor, selHGRDbgcolor,
                           c000000},
    [SchemeFlexSelDWDL] = {titleselfgcolor, selDWDLbgcolor, selDWDLbgcolor,
                           c000000},
    [SchemeFlexSelSPRL] = {titleselfgcolor, selSPRLbgcolor, selSPRLbgcolor,
                           c000000},
    [SchemeFlexSelFloat] = {titleselfgcolor, selfloatbgcolor, selfloatbgcolor,
                            c000000},
};

const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL};
static Sp scratchpads[] = {
    /* name          cmd  */
    {"spterm", spcmd1},
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by
 * changing the number of strings in the tags array. This build does things a
 * bit different which has some added benefits. If you need to change the number
 * of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
 * "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1
 * through 9, while the tags for the second monitor would be named A through I.
 * A third monitor would start again at 1 through 9 while the tags on a fourth
 * monitor would also be named A through I. Note the tags count of NUMTAGS*2 in
 * the array initialiser which defines how many tag text / icon exists in the
 * array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both
 * cases work the same from a technical standpoint - the icon index is derived
 * from the tag index and the monitor index. If the icon index is is greater
 * than the number of tag icons then it will wrap around until it an icon
 * matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration
 * patches.
 */
static char *tagicons[][NUMTAGS] = {
    [DEFAULT_TAGS] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"},
    [ALTERNATIVE_TAGS] = {"🧸", "B", "C", "D", "E", "F", "G", "H", "I"},
    [ALT_TAGS_DECORATION] = {"<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>",
                             "<8>", "<9>"},
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields
 * depending on the patches you enable.
 */
static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     *	WM_WINDOW_ROLE(STRING) = role
     *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
     */
    RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
        RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
            RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
                RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
                    RULE(.class = "Gimp", .tags = 1 << 4)
                        RULE(.class = "Firefox", .tags = 1 << 7)
                            RULE(.instance = "spterm", .tags = SPTAG(0),
                                 .isfloating = 1)};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for
 * active?) bar - bar index, 0 is default, 1 is extrabar alignment - how the
 * module is aligned compared to other modules widthfunc, drawfunc, clickfunc -
 * providing bar module width, draw and click functions name - does nothing,
 * intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
    /* monitor  bar    alignment         widthfunc                drawfunc
       clickfunc                name */
    {-1, 0, BAR_ALIGN_LEFT, width_tags, draw_tags, click_tags, "tags"},
    {0, 0, BAR_ALIGN_RIGHT, width_systray, draw_systray, click_systray,
     "systray"},
    {-1, 0, BAR_ALIGN_LEFT, width_ltsymbol, draw_ltsymbol, click_ltsymbol,
     "layout"},
    {0, 0, BAR_ALIGN_RIGHT, width_status2d, draw_status2d, click_status2d,
     "status2d"},
    {-1, 0, BAR_ALIGN_NONE, width_flexwintitle, draw_flexwintitle,
     click_flexwintitle, "flexwintitle"},
};

/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"><>", NULL}, /* no layout function means floating behavior */
    {"[M]", monocle},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {"HHH", grid},
    {NULL, NULL},
};

/* key definitions */
#define TERM "st"
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, comboview, {.ui = 1 << TAG}},                                  \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, combotag, {.ui = 1 << TAG}},                   \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},    \
      {MODKEY | Mod1Mask | ShiftMask, KEY, swaptags, {.ui = 1 << TAG}},        \
      {MODKEY | Mod1Mask, KEY, tagnextmon, {.ui = 1 << TAG}},                  \
      {MODKEY | Mod1Mask | ControlMask, KEY, tagprevmon, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL }                       \
  }

/* commands */
static char dmenumon[2] =
    "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"dmenu_run", "-m",
                                 dmenumon,    "-fn",
                                 dmenufont,   "-nb",
                                 normbgcolor, "-nf",
                                 normfgcolor, "-sb",
                                 selbgcolor,  "-sf",
                                 selfgcolor,  topbar ? NULL : "-b",
                                 NULL};
static const char *termcmd[] = {"st", NULL};

static const char *browsercmd[] = {"firefox", NULL};
static const char *spotifycmd[] = {"spotify", NULL};
static const char *shutdowncmd[] = {"/home/matthewrose/.scripts/endsession",
                                    NULL};
static const char *rebootcmd[] = {"reboot", NULL};
static const char *lockcmd[] = {"lockscreen", NULL};
static const char *pcmanfmcmd[] = {"pcmanfm", NULL};
static const char *codecmd[] = {"code", "-n", NULL};
static const char *configscmd[] = {
    "/home/matthewrose/.config/dmenu/dmenu-edit-configs.sh", NULL};
static const char *rangercmd[] = {TERM, "-e", "ranger", NULL};
static const char *htopcmd[] = {TERM, "-e", "htop", NULL};
static const char *flameshotguicmd[] = {
    "flameshot", "gui", "-p", "/home/matthewrose/Pictures/screenshots", NULL};
static const char *flameshotfullcmd[] = {
    "flameshot", "full", "-p", "/home/matthewrose/Pictures/screenshots", NULL};
static const char *developmentdircmd[] = {
    TERM, "-e", "nvim", "/home/matthewrose/Programming", NULL};
static const char *nmtuicmd[] = {TERM, "-e", "nmtui", NULL};
static const char *vifmcmd[] = {TERM, "-e", "vifmrun", NULL};

static const char *playbuttoncmd[] = {"playerctl", "play-pause", NULL};
static const char *pausebuttoncmd[] = {"playerctl", "play-pause", NULL};
static const char *nextbuttoncmd[] = {"playerctl", "next", NULL};
static const char *prevbuttoncmd[] = {"playerctl", "previous", NULL};

static const char *brightnessupcmd[] = {"xbacklight", "-inc", "20", NULL};
static const char *brightnessdowncmd[] = {"xbacklight", "-dec", "20", NULL};

static const char *audioupcmd[] = {"pactl", "set-sink-volume", "@DEFAULT_SINK@",
                                   "+5%", NULL};
static const char *audiodowncmd[] = {"pactl", "set-sink-volume",
                                     "@DEFAULT_SINK@", "-5%", NULL};
static const char *audiomutecmd[] = {"pactl", "set-sink-mute", "@DEFAULT_SINK@",
                                     "toggle", NULL};

static const char *qutebrowsercmd[] = {"qutebrowser", NULL};

static Key keys[] = {
    /* modifier                     key            function argument */
    {MODKEY | ShiftMask, XK_Return, spawn, {.v = dmenucmd}},
    {MODKEY, XK_Return, spawn, {.v = termcmd}},
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY | ControlMask, XK_space, focusmaster, {0}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY | ShiftMask, XK_j, rotatestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, rotatestack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {0}},
    {MODKEY | ControlMask, XK_r, reorganizetags, {0}},
    {MODKEY, XK_backslash, zoom, {0}},
    {MODKEY | Mod1Mask, XK_u, incrgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_u, incrgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_i, incrigaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_o, incrogaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | Mod1Mask | ShiftMask, XK_9, incrovgaps, {.i = -1}},
    {MODKEY | Mod1Mask, XK_0, togglegaps, {0}},
    {MODKEY | Mod1Mask | ShiftMask, XK_0, defaultgaps, {0}},
    {MODKEY, XK_Tab, view, {0}},
    {MODKEY | Mod1Mask, XK_Tab, shiftviewclients, {.i = -1}},
    {MODKEY | Mod1Mask, XK_backslash, shiftviewclients, {.i = +1}},
    {MODKEY | ControlMask, XK_z, showhideclient, {0}},
    {MODKEY | ShiftMask, XK_c, killclient, {0}},
    {MODKEY | ShiftMask, XK_r, self_restart, {0}},
    {MODKEY | ShiftMask, XK_q, quit, {0}},
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_grave, togglescratch, {.ui = 0}},
    {MODKEY | ControlMask, XK_grave, setscratch, {.ui = 0}},
    {MODKEY | ShiftMask, XK_grave, removescratch, {.ui = 0}},
    {MODKEY | ShiftMask, XK_s, togglesticky, {0}},
    {MODKEY, XK_0, view, {.ui = ~SPTAGMASK}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~SPTAGMASK}},
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_F1, tagall, {.v = "F1"}},
    {MODKEY | ShiftMask, XK_F2, tagall, {.v = "F2"}},
    {MODKEY | ShiftMask, XK_F3, tagall, {.v = "F3"}},
    {MODKEY | ShiftMask, XK_F4, tagall, {.v = "F4"}},
    {MODKEY | ShiftMask, XK_F5, tagall, {.v = "F5"}},
    {MODKEY | ShiftMask, XK_F6, tagall, {.v = "F6"}},
    {MODKEY | ShiftMask, XK_F7, tagall, {.v = "F7"}},
    {MODKEY | ShiftMask, XK_F8, tagall, {.v = "F8"}},
    {MODKEY | ShiftMask, XK_F9, tagall, {.v = "F9"}},
    {MODKEY | ControlMask, XK_F1, tagall, {.v = "1"}},
    {MODKEY | ControlMask, XK_F2, tagall, {.v = "2"}},
    {MODKEY | ControlMask, XK_F3, tagall, {.v = "3"}},
    {MODKEY | ControlMask, XK_F4, tagall, {.v = "4"}},
    {MODKEY | ControlMask, XK_F5, tagall, {.v = "5"}},
    {MODKEY | ControlMask, XK_F6, tagall, {.v = "6"}},
    {MODKEY | ControlMask, XK_F7, tagall, {.v = "7"}},
    {MODKEY | ControlMask, XK_F8, tagall, {.v = "8"}},
    {MODKEY | ControlMask, XK_F9, tagall, {.v = "9"}},

    // My keybindings:
    {MODKEY, XK_w, spawn, {.v = browsercmd}},
    {MODKEY, XK_s, spawn, {.v = spotifycmd}},
    {MODKEY | ShiftMask, XK_x, spawn, {.v = shutdowncmd}},
    {MODKEY, XK_p, spawn, {.v = pcmanfmcmd}},
    {MODKEY | ShiftMask, XK_p, spawn, {.v = codecmd}},
    {MODKEY, XK_r, spawn, {.v = vifmcmd}},
    {0, XK_Print, spawn, {.v = flameshotguicmd}},
    {0, XF86XK_AudioPlay, spawn, {.v = playbuttoncmd}},
    {0, XF86XK_AudioPause, spawn, {.v = pausebuttoncmd}},
    {0, XF86XK_AudioPrev, spawn, {.v = prevbuttoncmd}},
    {0, XF86XK_AudioNext, spawn, {.v = nextbuttoncmd}},
    {0, XF86XK_MonBrightnessUp, spawn, {.v = brightnessupcmd}},
    {0, XF86XK_MonBrightnessDown, spawn, {.v = brightnessdowncmd}},
    {0, XF86XK_AudioRaiseVolume, spawn,
     SHCMD("pamixer -i 5; kill -44 $(pidof dwmblocks)")},
    {0, XF86XK_AudioLowerVolume, spawn,
     SHCMD("pamixer -d 5; kill -44 $(pidof dwmblocks)")},
    {0, XF86XK_AudioMute, spawn, {.v = audiomutecmd}},
    {MODKEY | ShiftMask, XK_e, spawn, {.v = configscmd}},
    {MODKEY, XK_q, spawn, {.v = qutebrowsercmd}},

    {MODKEY, XK_KP_7, moveplace, {.ui = WIN_NW}}, /* XK_KP_Home,  */
    {MODKEY, XK_KP_8, moveplace, {.ui = WIN_N}},  /* XK_KP_Up,    */
    {MODKEY, XK_KP_9, moveplace, {.ui = WIN_NE}}, /* XK_KP_Prior, */
    {MODKEY, XK_KP_4, moveplace, {.ui = WIN_W}},  /* XK_KP_Left,  */
    {MODKEY, XK_KP_5, moveplace, {.ui = WIN_C}},  /* XK_KP_Begin, */
    {MODKEY, XK_KP_6, moveplace, {.ui = WIN_E}},  /* XK_KP_Right, */
    {MODKEY, XK_KP_1, moveplace, {.ui = WIN_SW}}, /* XK_KP_End,   */
    {MODKEY, XK_KP_2, moveplace, {.ui = WIN_S}},  /* XK_KP_Down,  */
    {MODKEY, XK_KP_3, moveplace, {.ui = WIN_SE}}, /* XK_KP_Next,  */
    /* Note that due to key limitations the below example kybindings are defined
     * with a Mod3Mask, which is not always readily available. Refer to the
     * patch wiki for more details. */
    /* Client position is limited to monitor window area */
    {Mod3Mask, XK_u, floatpos, {.v = "-26x -26y"}},      // ↖
    {Mod3Mask, XK_i, floatpos, {.v = "  0x -26y"}},      // ↑
    {Mod3Mask, XK_o, floatpos, {.v = " 26x -26y"}},      // ↗
    {Mod3Mask, XK_j, floatpos, {.v = "-26x   0y"}},      // ←
    {Mod3Mask, XK_l, floatpos, {.v = " 26x   0y"}},      // →
    {Mod3Mask, XK_m, floatpos, {.v = "-26x  26y"}},      // ↙
    {Mod3Mask, XK_comma, floatpos, {.v = "  0x  26y"}},  // ↓
    {Mod3Mask, XK_period, floatpos, {.v = " 26x  26y"}}, // ↘
    /* Absolute positioning (allows moving windows between monitors) */
    {Mod3Mask | ControlMask, XK_u, floatpos, {.v = "-26a -26a"}},      // ↖
    {Mod3Mask | ControlMask, XK_i, floatpos, {.v = "  0a -26a"}},      // ↑
    {Mod3Mask | ControlMask, XK_o, floatpos, {.v = " 26a -26a"}},      // ↗
    {Mod3Mask | ControlMask, XK_j, floatpos, {.v = "-26a   0a"}},      // ←
    {Mod3Mask | ControlMask, XK_l, floatpos, {.v = " 26a   0a"}},      // →
    {Mod3Mask | ControlMask, XK_m, floatpos, {.v = "-26a  26a"}},      // ↙
    {Mod3Mask | ControlMask, XK_comma, floatpos, {.v = "  0a  26a"}},  // ↓
    {Mod3Mask | ControlMask, XK_period, floatpos, {.v = " 26a  26a"}}, // ↘
    /* Resize client, client center position is fixed which means that client
       expands in all directions */
    {Mod3Mask | ShiftMask, XK_u, floatpos, {.v = "-26w -26h"}},      // ↖
    {Mod3Mask | ShiftMask, XK_i, floatpos, {.v = "  0w -26h"}},      // ↑
    {Mod3Mask | ShiftMask, XK_o, floatpos, {.v = " 26w -26h"}},      // ↗
    {Mod3Mask | ShiftMask, XK_j, floatpos, {.v = "-26w   0h"}},      // ←
    {Mod3Mask | ShiftMask, XK_k, floatpos, {.v = "800W 800H"}},      // ·
    {Mod3Mask | ShiftMask, XK_l, floatpos, {.v = " 26w   0h"}},      // →
    {Mod3Mask | ShiftMask, XK_m, floatpos, {.v = "-26w  26h"}},      // ↙
    {Mod3Mask | ShiftMask, XK_comma, floatpos, {.v = "  0w  26h"}},  // ↓
    {Mod3Mask | ShiftMask, XK_period, floatpos, {.v = " 26w  26h"}}, // ↘
    /* Client is positioned in a floating grid, movement is relative to client's
       current position */
    {Mod3Mask | Mod1Mask, XK_u, floatpos, {.v = "-1p -1p"}},      // ↖
    {Mod3Mask | Mod1Mask, XK_i, floatpos, {.v = " 0p -1p"}},      // ↑
    {Mod3Mask | Mod1Mask, XK_o, floatpos, {.v = " 1p -1p"}},      // ↗
    {Mod3Mask | Mod1Mask, XK_j, floatpos, {.v = "-1p  0p"}},      // ←
    {Mod3Mask | Mod1Mask, XK_k, floatpos, {.v = " 0p  0p"}},      // ·
    {Mod3Mask | Mod1Mask, XK_l, floatpos, {.v = " 1p  0p"}},      // →
    {Mod3Mask | Mod1Mask, XK_m, floatpos, {.v = "-1p  1p"}},      // ↙
    {Mod3Mask | Mod1Mask, XK_comma, floatpos, {.v = " 0p  1p"}},  // ↓
    {Mod3Mask | Mod1Mask, XK_period, floatpos, {.v = " 1p  1p"}}, // ↘
    {MODKEY | ControlMask, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, XK_period, cyclelayout, {.i = +1}},
    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask           button          function
       argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button1, togglewin, {0}},
    {ClkWinTitle, 0, Button3, showhideclient, {0}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = termcmd}},
    {ClkClientWin, MODKEY, Button1, movemouse, {0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
