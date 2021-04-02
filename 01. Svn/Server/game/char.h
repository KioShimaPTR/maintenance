//Search:

		LPEVENT				m_pkWarpEvent;

//Add below:

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
		LPEVENT				m_pkMainTimer;
#endif

//Search:
		int				GetSyncHackCount() { return m_iSyncHackCount; }

//Add below

#ifdef ENABLE_COSBY_MAINTENANCE_SYSTEM
	public:
		void StartMainDataEvent();
#endif