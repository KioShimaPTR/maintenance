#add imports
import uimaintenance

#Search:

		textTail.EnablePKTitle(constInfo.PVPMODE_ENABLE)

#Add below:

		maintenance = uimaintenance.MaintenanceWindow()
		maintenance.Open(constInfo.maintenanceinfo["time"],constInfo.maintenanceinfo["duration"],constInfo.maintenanceinfo["active"])
		self.maintenance = maintenance


#Search:

		# QUEST_CONFIRM
		self.confirmDialog = None
		# END_OF_QUEST_CONFIRM

#Add below:

		self.maintenance.Close()
		self.maintenance = None

#Search:

print "---------------------------------------------------------------------------- CLOSE GAME WINDOW"

#Add below:

	def Maintenancegui(self,time,duration,active):
		constInfo.maintenanceinfo["time"] = int(time)
		constInfo.maintenanceinfo["duration"] = int(duration)
		constInfo.maintenanceinfo["active"] = int(active)

		if constInfo.maintenanceinfo["active"] == 1:
			self.maintenance.Open(constInfo.maintenanceinfo["time"],constInfo.maintenanceinfo["duration"],constInfo.maintenanceinfo["active"])
		else:
			self.maintenance.Close()

#Search:

			"PlayMusic"				: self.__PlayMusic,

#Add below:

			"Maintenancegui"	: self.Maintenancegui,

#Search:

	def __PlayMusic(self, flag, filename):

#Add below function:

	def maintenanceadminopen(self):
		if not "[" in player.GetName():
			return

		self.Maintenancedialog = uimaintenance.MaintenanceDialog()
		self.Maintenancedialog.Show()

#Search:

		onPressKeyDict[app.DIK_F4]	= lambda : self.__PressQuickSlot(7)

#Add below:

		onPressKeyDict[app.DIK_F12]	= lambda : self.maintenanceadminopen()