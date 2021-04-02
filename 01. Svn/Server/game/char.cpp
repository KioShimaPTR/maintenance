//Search:

	m_pkChrStone = NULL;

//Add below:


#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
	m_pkMainTimer = NULL;
#endif

//Search:

	event_cancel(&m_pkPoisonEvent);

//Add below:

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
	event_cancel(&m_pkMainTimer);
#endif

// Search: 

void CHARACTER::ToggleMonsterLog()

//Add below function:

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
EVENTFUNC(main_data_event)
{
	char_event_info* info = dynamic_cast<char_event_info*>( event->info );

	if (!info)
		return 0;

	LPCHARACTER	ch = info->ch;

	if (!ch || !ch->GetDesc())
		return 0;

	quest::CQuestManager& R = quest::CQuestManager::instance();

	if (R.GetEventFlag("MainActive") == 0)
	{
		ch->ChatPacket(CHAT_TYPE_COMMAND, "Maintenancegui 0 0 0");
		return 1;
	}

	if (ch->IsPC() == true)
	{
		if (R.GetEventFlag("MainActive") == 1)
		{
			if (get_global_time() > R.GetEventFlag("MainTime"))
			{
				R.SetEventFlag("MainTime", 0);
				R.SetEventFlag("MainMin", 0);
				R.SetEventFlag("MainActive", 0);

				ch->ChatPacket(CHAT_TYPE_COMMAND, "Maintenancegui 0 0 0");

				TPacketGGShutdown p;
				p.bHeader = HEADER_GG_SHUTDOWN;
				P2P_MANAGER::instance().Send(&p, sizeof(TPacketGGShutdown));

				Shutdown(10);

				return 0;
			}
			else
			{
				ch->ChatPacket(CHAT_TYPE_COMMAND, "Maintenancegui %d %d %d", R.GetEventFlag("MainTime"), R.GetEventFlag("MainMin"), R.GetEventFlag("MainActive"));
				return PASSES_PER_SEC(1);
			}
		}
	}
}

void CHARACTER::StartMainDataEvent()
{
	char_event_info* info = AllocEventInfo<char_event_info>();
	info->ch = this;
	m_pkMainTimer = event_create(main_data_event, info, PASSES_PER_SEC(1));
}
#endif