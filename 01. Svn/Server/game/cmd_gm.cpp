//Add to last

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
ACMD(do_main)
{
	char arg1[256], arg2[256], arg3[256];
	three_arguments(argument, arg1, sizeof(arg1), arg2, sizeof(arg2), arg3, sizeof(arg3));

	if (!*arg1 || 0 == arg1[0] || !*arg2 || 0 == arg2[0])
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "bak�m hata.");
		return;
	}

	if (!sadece_rakam(arg1))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Sadece sadece rakamdan olu�abilir saniye cinsinden yaz�n�z.");
		return;
	}

	if (!sadece_rakam(arg2))
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Bak�m�n ne kadar s�rece�i sadece rakamdan olu�abilir ka� dakika s�rece�ini yaz�n�z.");
		return;
	}

	int second = 0;
	str_to_number(second, arg1);

	if (second <= 0 || second == NULL)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "S�reye negatif bir say� giremez veya bo� b�rakamazs�n�z.");
		return;
	}

	DWORD min = 0;
	str_to_number(min, arg2);

	if (min <= 0 || min == NULL)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Bak�m�n ne kadar s�rece�ine negatif bir say� giremeziniz veya bo� b�rakamazs�n�z.");
		return;
	}

	DWORD active = 0;
	str_to_number(active, arg3);

	if (active == NULL)
	{
		ch->ChatPacket(CHAT_TYPE_INFO, "Hata.");
		return;
	}

	quest::CQuestManager& R = quest::CQuestManager::instance();
	R.RequestSetEventFlag("MainTime", get_global_time() + second);
	R.RequestSetEventFlag("MainMin", min);
	R.RequestSetEventFlag("MainActive", active);
	ch->StartMainDataEvent();
	ch->ChatPacket(CHAT_TYPE_INFO, "Bak�m ba�lad� %d saniye kald�, bak�m %d dakika s�recektir.", second, min);
}

ACMD(do_main_close)
{
	event_cancel(&m_pkMainTimer);
	quest::CQuestManager& R = quest::CQuestManager::instance();
	R.SetEventFlag("MainTime", 0);
	R.SetEventFlag("MainMin", 0);
	R.SetEventFlag("MainActive", 0);
	ch->ChatPacket(CHAT_TYPE_COMMAND, "Maintenancegui 0 0 0");
}
#endif