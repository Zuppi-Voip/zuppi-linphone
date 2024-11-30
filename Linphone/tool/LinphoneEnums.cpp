/*
 * Copyright (c) 2024 Belledonne Communications SARL.
 *
 * This file is part of linphone-desktop
 * (see https://www.zuppi.site).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ZuppiEnums.hpp"
#include "Constants.hpp"

#include <QQmlEngine>
#include <QString>

// =============================================================================

void ZuppiEnums::registerMetaTypes() {
	qRegisterMetaType<ZuppiEnums::CallState>();
	qRegisterMetaType<ZuppiEnums::CallStatus>();
	qRegisterMetaType<ZuppiEnums::SecurityLevel>();
	qRegisterMetaType<ZuppiEnums::ChatMessageState>();
	qRegisterMetaType<ZuppiEnums::ChatRoomState>();
	qRegisterMetaType<ZuppiEnums::ConferenceLayout>();
	qRegisterMetaType<ZuppiEnums::ConferenceInfoState>();
	qRegisterMetaType<ZuppiEnums::ConferenceSchedulerState>();
	qRegisterMetaType<ZuppiEnums::EventLogType>();
	qRegisterMetaType<ZuppiEnums::FriendCapability>();
	qRegisterMetaType<ZuppiEnums::MediaEncryption>();
	qRegisterMetaType<ZuppiEnums::ParticipantDeviceState>();
	qRegisterMetaType<ZuppiEnums::RecorderState>();
	qRegisterMetaType<ZuppiEnums::RegistrationState>();
	qRegisterMetaType<ZuppiEnums::TunnelMode>();
	qRegisterMetaType<ZuppiEnums::TransportType>();
	qRegisterMetaType<ZuppiEnums::VideoSourceScreenSharingType>();
	qmlRegisterUncreatableMetaObject(ZuppiEnums::staticMetaObject, Constants::MainQmlUri, 1, 0, "ZuppiEnums",
	                                 "Only enums");
}

linphone::MediaEncryption ZuppiEnums::toZuppi(const ZuppiEnums::MediaEncryption &data) {
	return static_cast<linphone::MediaEncryption>(data);
}
ZuppiEnums::MediaEncryption ZuppiEnums::fromZuppi(const linphone::MediaEncryption &data) {
	return static_cast<ZuppiEnums::MediaEncryption>(data);
}
QString ZuppiEnums::toString(ZuppiEnums::MediaEncryption encryption) {
	switch (encryption) {
		case ZuppiEnums::MediaEncryption::Dtls:
			return "DTLS";
		case ZuppiEnums::MediaEncryption::None:
			return "None";
		case ZuppiEnums::MediaEncryption::Srtp:
			return "SRTP";
		case ZuppiEnums::MediaEncryption::Zrtp:
			return "ZRTP";
		default:
			return QString();
	}
}

linphone::Friend::Capability ZuppiEnums::toZuppi(const ZuppiEnums::FriendCapability &data) {
	return static_cast<linphone::Friend::Capability>(data);
}
ZuppiEnums::FriendCapability ZuppiEnums::fromZuppi(const linphone::Friend::Capability &data) {
	return static_cast<ZuppiEnums::FriendCapability>(data);
}

linphone::EventLog::Type ZuppiEnums::toZuppi(const ZuppiEnums::EventLogType &data) {
	return static_cast<linphone::EventLog::Type>(data);
}
ZuppiEnums::EventLogType ZuppiEnums::fromZuppi(const linphone::EventLog::Type &data) {
	return static_cast<ZuppiEnums::EventLogType>(data);
}

linphone::ChatMessage::State ZuppiEnums::toZuppi(const ZuppiEnums::ChatMessageState &data) {
	return static_cast<linphone::ChatMessage::State>(data);
}
ZuppiEnums::ChatMessageState ZuppiEnums::fromZuppi(const linphone::ChatMessage::State &data) {
	return static_cast<ZuppiEnums::ChatMessageState>(data);
}

linphone::ChatRoom::State ZuppiEnums::toZuppi(const ZuppiEnums::ChatRoomState &data) {
	return static_cast<linphone::ChatRoom::State>(data);
}

ZuppiEnums::ChatRoomState ZuppiEnums::fromZuppi(const linphone::ChatRoom::State &data) {
	return static_cast<ZuppiEnums::ChatRoomState>(data);
}

linphone::Call::State ZuppiEnums::toZuppi(const ZuppiEnums::CallState &data) {
	return static_cast<linphone::Call::State>(data);
}
ZuppiEnums::CallState ZuppiEnums::fromZuppi(const linphone::Call::State &data) {
	return static_cast<ZuppiEnums::CallState>(data);
}

linphone::Call::Status ZuppiEnums::toZuppi(const ZuppiEnums::CallStatus &data) {
	return static_cast<linphone::Call::Status>(data);
}
ZuppiEnums::CallStatus ZuppiEnums::fromZuppi(const linphone::Call::Status &data) {
	return static_cast<ZuppiEnums::CallStatus>(data);
}

QString ZuppiEnums::toString(const ZuppiEnums::CallStatus &data) {
	switch (data) {
		case ZuppiEnums::CallStatus::Declined:
			return "Declined";
		case ZuppiEnums::CallStatus::Missed:
			return "Missed";
		case ZuppiEnums::CallStatus::Success:
			return "Success";
		case ZuppiEnums::CallStatus::Aborted:
			return "Aborted";
		case ZuppiEnums::CallStatus::EarlyAborted:
			return "EarlyAborted";
		case ZuppiEnums::CallStatus::AcceptedElsewhere:
			return "AcceptedElsewhere";
		case ZuppiEnums::CallStatus::DeclinedElsewhere:
			return "DeclinedElsewhere";
		default:
			return QString();
	}
}

linphone::SecurityLevel ZuppiEnums::toZuppi(const ZuppiEnums::SecurityLevel &level) {
	return static_cast<linphone::SecurityLevel>(level);
}

ZuppiEnums::SecurityLevel ZuppiEnums::fromZuppi(const linphone::SecurityLevel &level) {
	return static_cast<ZuppiEnums::SecurityLevel>(level);
}

ZuppiEnums::CallDir ZuppiEnums::fromZuppi(const linphone::Call::Dir &data) {
	return static_cast<ZuppiEnums::CallDir>(data);
}

linphone::Call::Dir ZuppiEnums::toZuppi(const ZuppiEnums::CallDir &data) {
	return static_cast<linphone::Call::Dir>(data);
}

QString ZuppiEnums::toString(const ZuppiEnums::CallDir &data) {
	switch (data) {
		case ZuppiEnums::CallDir::Incoming:
			return QObject::tr("Entrant");
		case ZuppiEnums::CallDir::Outgoing:
			return QObject::tr("Sortant");
		default:
			return QString();
	}
}

ZuppiEnums::Reason ZuppiEnums::fromZuppi(const linphone::Reason &data) {
	return static_cast<ZuppiEnums::Reason>(data);
}

linphone::Reason ZuppiEnums::toZuppi(const ZuppiEnums::Reason &data) {
	return static_cast<linphone::Reason>(data);
}

linphone::Conference::Layout ZuppiEnums::toZuppi(const ZuppiEnums::ConferenceLayout &layout) {
	if (layout != ZuppiEnums::ConferenceLayout::AudioOnly) return static_cast<linphone::Conference::Layout>(layout);
	else return linphone::Conference::Layout::Grid; // Audio Only mode
}

ZuppiEnums::ConferenceLayout ZuppiEnums::fromZuppi(const linphone::Conference::Layout &layout) {
	return static_cast<ZuppiEnums::ConferenceLayout>(layout);
}

linphone::ConferenceInfo::State ZuppiEnums::toZuppi(const ZuppiEnums::ConferenceInfoState &state) {
	return static_cast<linphone::ConferenceInfo::State>(state);
}

ZuppiEnums::ConferenceInfoState ZuppiEnums::fromZuppi(const linphone::ConferenceInfo::State &state) {
	return static_cast<ZuppiEnums::ConferenceInfoState>(state);
}

linphone::ConferenceScheduler::State ZuppiEnums::toZuppi(const ZuppiEnums::ConferenceSchedulerState &state) {
	return static_cast<linphone::ConferenceScheduler::State>(state);
}

ZuppiEnums::ConferenceSchedulerState ZuppiEnums::fromZuppi(const linphone::ConferenceScheduler::State &state) {
	return static_cast<ZuppiEnums::ConferenceSchedulerState>(state);
}

linphone::ConsolidatedPresence ZuppiEnums::toZuppi(const ZuppiEnums::ConsolidatedPresence &data) {
	return static_cast<linphone::ConsolidatedPresence>(data);
}
ZuppiEnums::ConsolidatedPresence ZuppiEnums::fromZuppi(const linphone::ConsolidatedPresence &data) {
	return static_cast<ZuppiEnums::ConsolidatedPresence>(data);
}

linphone::MagicSearch::Aggregation ZuppiEnums::toZuppi(const ZuppiEnums::MagicSearchAggregation &data) {
	return static_cast<linphone::MagicSearch::Aggregation>(data);
}
ZuppiEnums::MagicSearchAggregation ZuppiEnums::fromZuppi(const linphone::MagicSearch::Aggregation &data) {
	return static_cast<ZuppiEnums::MagicSearchAggregation>(data);
}

linphone::MagicSearch::Source ZuppiEnums::toZuppi(const ZuppiEnums::MagicSearchSource &data) {
	return static_cast<linphone::MagicSearch::Source>(data);
}
ZuppiEnums::MagicSearchSource ZuppiEnums::fromZuppi(const linphone::MagicSearch::Source &data) {
	return static_cast<ZuppiEnums::MagicSearchSource>(data);
}

linphone::LogLevel ZuppiEnums::toZuppi(const QtMsgType &data) {
	switch (data) {
		case QtDebugMsg:
			return linphone::LogLevel::Debug;
		case QtWarningMsg:
			return linphone::LogLevel::Warning;
		case QtCriticalMsg:
			return linphone::LogLevel::Error;
		case QtFatalMsg:
			return linphone::LogLevel::Fatal;
		case QtInfoMsg:
			return linphone::LogLevel::Message;
		default:
			return linphone::LogLevel::Trace;
	}
}

QtMsgType ZuppiEnums::fromZuppi(const linphone::LogLevel &data) {
	switch (data) {
		case linphone::LogLevel::Debug:
			return QtDebugMsg;
		case linphone::LogLevel::Trace:
			return QtInfoMsg;
		case linphone::LogLevel::Message:
			return QtInfoMsg;
		case linphone::LogLevel::Warning:
			return QtWarningMsg;
		case linphone::LogLevel::Error:
			return QtCriticalMsg;
		case linphone::LogLevel::Fatal:
			return QtFatalMsg;
		default:
			return QtInfoMsg;
	}
}

linphone::ParticipantDevice::State ZuppiEnums::toZuppi(const ZuppiEnums::ParticipantDeviceState &state) {
	return static_cast<linphone::ParticipantDevice::State>(state);
}

ZuppiEnums::ParticipantDeviceState ZuppiEnums::fromZuppi(const linphone::ParticipantDevice::State &state) {
	return static_cast<ZuppiEnums::ParticipantDeviceState>(state);
}

linphone::Participant::Role ZuppiEnums::toZuppi(const ZuppiEnums::ParticipantRole &role) {
	return static_cast<linphone::Participant::Role>(role);
}

ZuppiEnums::ParticipantRole ZuppiEnums::fromZuppi(const linphone::Participant::Role &role) {
	return static_cast<ZuppiEnums::ParticipantRole>(role);
}

linphone::Tunnel::Mode ZuppiEnums::toZuppi(const ZuppiEnums::TunnelMode &data) {
	return static_cast<linphone::Tunnel::Mode>(data);
}
ZuppiEnums::TunnelMode ZuppiEnums::fromZuppi(const linphone::Tunnel::Mode &data) {
	return static_cast<ZuppiEnums::TunnelMode>(data);
}

linphone::Recorder::State ZuppiEnums::toZuppi(const ZuppiEnums::RecorderState &data) {
	return static_cast<linphone::Recorder::State>(data);
}
ZuppiEnums::RecorderState ZuppiEnums::fromZuppi(const linphone::Recorder::State &data) {
	return static_cast<ZuppiEnums::RecorderState>(data);
}

linphone::RegistrationState ZuppiEnums::toZuppi(const ZuppiEnums::RegistrationState &data) {
	return static_cast<linphone::RegistrationState>(data);
}

ZuppiEnums::RegistrationState ZuppiEnums::fromZuppi(const linphone::RegistrationState &data) {
	return static_cast<ZuppiEnums::RegistrationState>(data);
}

linphone::TransportType ZuppiEnums::toZuppi(const ZuppiEnums::TransportType &type) {
	return static_cast<linphone::TransportType>(type);
}
ZuppiEnums::TransportType ZuppiEnums::fromZuppi(const linphone::TransportType &type) {
	return static_cast<ZuppiEnums::TransportType>(type);
}
QString ZuppiEnums::toString(const ZuppiEnums::TransportType &type) {
	switch (type) {
		case TransportType::Tcp:
			return "TCP";
		case TransportType::Udp:
			return "UDP";
		case TransportType::Tls:
			return "TLS";
		case TransportType::Dtls:
			return "DTLS";
		default:
			return QString();
	}
}
void ZuppiEnums::fromString(const QString &transportType, ZuppiEnums::TransportType *transport) {
	if (transportType.toUpper() == QLatin1String("TCP")) *transport = TransportType::Tcp;
	else if (transportType.toUpper() == QLatin1String("UDP")) *transport = TransportType::Udp;
	else if (transportType.toUpper() == QLatin1String("TLS")) *transport = TransportType::Tls;
	else if (transportType.toUpper() == QLatin1String("DTLS")) *transport = TransportType::Dtls;
	else *transport = TransportType::Udp;
}

linphone::VideoSourceScreenSharingType
ZuppiEnums::toZuppi(const ZuppiEnums::VideoSourceScreenSharingType &type) {
	return static_cast<linphone::VideoSourceScreenSharingType>(type);
}
ZuppiEnums::VideoSourceScreenSharingType
ZuppiEnums::fromZuppi(const linphone::VideoSourceScreenSharingType &type) {
	return static_cast<ZuppiEnums::VideoSourceScreenSharingType>(type);
}
