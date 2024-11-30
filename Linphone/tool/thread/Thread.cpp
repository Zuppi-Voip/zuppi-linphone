/*
 * Copyright (c) 2010-2024 Belledonne Communications SARL.
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

#include "Thread.hpp"
#include "core/App.hpp"
#include <QDebug>

Thread::Thread(QObject *parent) : QThread(parent) {
}

void Thread::run() {
	mThreadId = new QObject();
	setlocale(LC_CTYPE, ".UTF8");
	int toExit = false;
	while (!toExit) {
		int result = exec();
		if (result <= 0) toExit = true;
	}
}
Thread::~Thread() {
	mThreadId->deleteLater();
}

QObject *Thread::getThreadId() {
	return mThreadId;
}

bool Thread::isInZuppiThread() {
	return QThread::currentThread() == App::getZuppiThread();
}

bool Thread::mustBeInZuppiThread(const QString &context) {
	bool isZuppiThread = isInZuppiThread();
	if (!isZuppiThread) { // Bracket to easier debugging.
		lCritical() << "[Thread] Not processing in Zuppi thread from " << context;
	}
	return isZuppiThread;
}

bool Thread::mustBeInMainThread(const QString &context) {
	if (!qApp) return true;
	bool isMainThread = QThread::currentThread() == qApp->thread();
	if (!isMainThread) {
		lCritical() << "[Thread] Not processing in Main thread from " << context;
	}
	return isMainThread;
}
