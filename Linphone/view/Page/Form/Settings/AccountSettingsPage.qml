import QtQuick
import QtQuick.Effects
import QtQuick.Layouts
import QtQuick.Controls.Basic as Control
import Zuppi
import UtilsCpp
import SettingsCpp

AbstractSettingsMenu {
	layoutsPath: "qrc:/qt/qml/Zuppi/view/Page/Layout/Settings"
	titleText: qsTr("Mon compte")
	property AccountProxy  accounts: AccountProxy {
		id: accountProxy
		sourceModel: AppCpp.accounts
	}
	property AccountGui account: accountProxy.defaultAccount
	signal accountRemoved()
	families: [
		{title: qsTr("Général"), layout: "AccountSettingsGeneralLayout", model: account},
		{title: qsTr("Paramètres de compte"), layout: "AccountSettingsParametersLayout", model: account}
	]
	Connections {
		target: account.core
		onRemoved: accountRemoved()
	}
}
