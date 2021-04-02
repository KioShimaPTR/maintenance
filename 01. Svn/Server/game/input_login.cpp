//Search:

	ch->ResetPlayTime();

//Add below:

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
	ch->StartMainDataEvent();
#endif