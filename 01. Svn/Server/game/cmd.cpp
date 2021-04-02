//add it somewhere convenient

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
ACMD(do_main);
ACMD(do_main_close);
#endif

//Search:

	{ "do_clear_affect", do_clear_affect, 	0, POS_DEAD,		GM_LOW_WIZARD},

//Add below:

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
	{ "main",	do_main,		0,			POS_DEAD,	GM_IMPLEMENTOR	},
	{ "mainclose",	do_main_close,		0,			POS_DEAD,	GM_IMPLEMENTOR	},
#endif