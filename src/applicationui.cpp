/*
 * Copyright (c) 2011-2015 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

#include <bb/data/JsonDataAccess>

static QString dataAssetsPath(const QString& fileName)
{
    return QDir::currentPath() + "/app/native/assets/data/" + fileName;
}
static QString dataPath(const QString& fileName)
{
    return QDir::currentPath() + "/data/" + fileName;
}

using namespace bb::cascades;
using namespace bb::data;

ApplicationUI::ApplicationUI() :
        QObject()
{
    // prepare the localization
    m_pTranslator = new QTranslator(this);
    m_pLocaleHandler = new LocaleHandler(this);

    bool res = QObject::connect(m_pLocaleHandler, SIGNAL(systemLanguageChanged()), this,
            SLOT(onSystemLanguageChanged()));
    // This is only available in Debug builds
    Q_ASSERT(res);
    // Since the variable is not used in the app, this is added to avoid a
    // compiler warning
    Q_UNUSED(res);

    // QTimer
    qmlRegisterType<QTimer>("org.ekkescorner.common", 1, 0, "QTimer");

    // initial load
    onSystemLanguageChanged();

    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    qml->setContextProperty("app", this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    // Set created root object as the application scene
    Application::instance()->setScene(root);
}

void ApplicationUI::onSystemLanguageChanged()
{
    QCoreApplication::instance()->removeTranslator(m_pTranslator);
    // Initiate, load and install the application translation files.
    QString locale_string = QLocale().name();
    QString file_name = QString("cascades_performance_biz_apps_%1").arg(locale_string);
    if (m_pTranslator->load(file_name, "app/native/qm")) {
        QCoreApplication::instance()->installTranslator(m_pTranslator);
    }
}

void ApplicationUI::checkIndexQStringList()
{
    qDebug() << "Start checkIndexQStringList";
    JsonDataAccess jda;
    QVariantList cacheList;
    QStringList myIndexes;
    int duplicates;
    cacheList = jda.load(dataAssetsPath("fakeName.json")).toList();
    duplicates = 0;
    QTime time;
    time.start();
    for (int i = 0; i < cacheList.size(); ++i) {
        QVariantMap fakeMap = cacheList.at(i).toMap();
        QString myIndex = fakeMap.value("Username").toString();
        if (myIndexes.contains(myIndex)) {
            duplicates++;
            qDebug() << "DUPLICATE: " << myIndex;
        } else {
            myIndexes << myIndex;
        }
    }
    QString result;
    result = "via QStringList\nduplicates: ";
    result.append(QString::number(duplicates)).append("\nTimer: ").append(
            QString::number(time.elapsed())).append(" mSeconds");
    qDebug() << "finish checkIndexQStringList";
    emit doneStringList(result);
}

void ApplicationUI::checkIndexQVariantMap()
{
    qDebug() << "Start checkIndexQVariantMap";
    JsonDataAccess jda;
    QVariantList cacheList;
    QVariantMap myIndexes;
    int duplicates;
    cacheList = jda.load(dataAssetsPath("fakeName.json")).toList();
    duplicates = 0;
    QTime time;
    time.start();
    for (int i = 0; i < cacheList.size(); ++i) {
        QVariantMap fakeMap = cacheList.at(i).toMap();
        QString myIndex = fakeMap.value("Username").toString();
        if (myIndexes.contains(myIndex)) {
            duplicates++;
            qDebug() << "DUPLICATE: " << myIndex;
        } else {
            myIndexes.insert(myIndex, "");
        }
    }
    QString result;
    result = "via QVariantMap\nduplicates: ";
    result.append(QString::number(duplicates)).append("\nTimer: ").append(
            QString::number(time.elapsed())).append(" mSeconds");
    qDebug() << "finish checkIndexQVariantMap";
    emit doneVariantMap(result);
}

void ApplicationUI::checkIndexQMap()
{
    qDebug() << "Start checkIndexQMap";
    JsonDataAccess jda;
    QVariantList cacheList;
    QMap<QString, QString> myIndexes;
    int duplicates;
    cacheList = jda.load(dataAssetsPath("fakeName.json")).toList();
    duplicates = 0;
    QTime time;
    time.start();
    for (int i = 0; i < cacheList.size(); ++i) {
        QVariantMap fakeMap = cacheList.at(i).toMap();
        QString myIndex = fakeMap.value("Username").toString();
        if (myIndexes.contains(myIndex)) {
            duplicates++;
            qDebug() << "DUPLICATE: " << myIndex;
        } else {
            myIndexes.insert(myIndex, "");
        }
    }
    QString result;
    result = "via QMap<QString>\nduplicates: ";
    result.append(QString::number(duplicates)).append("\nTimer: ").append(
            QString::number(time.elapsed())).append(" mSeconds");
    qDebug() << "finish checkIndexQMap";
    emit doneMap(result);
}

void ApplicationUI::checkIndexQHash()
{
    qDebug() << "Start checkIndexQHash";
    JsonDataAccess jda;
    QVariantList cacheList;
    QHash<QString, QString> myIndexes;
    int duplicates;
    cacheList = jda.load(dataAssetsPath("fakeName.json")).toList();
    duplicates = 0;
    QTime time;
    time.start();
    for (int i = 0; i < cacheList.size(); ++i) {
        QVariantMap fakeMap = cacheList.at(i).toMap();
        QString myIndex = fakeMap.value("Username").toString();
        if (myIndexes.contains(myIndex)) {
            duplicates++;
            qDebug() << "DUPLICATE: " << myIndex;
        } else {
            myIndexes.insert(myIndex, "");
        }
    }
    QString result;
    result = "via QHash<QString>\nduplicates: ";
    result.append(QString::number(duplicates)).append("\nTimer: ").append(
            QString::number(time.elapsed())).append(" mSeconds");
    qDebug() << "finish checkIndexQHash";
    emit doneHash(result);
}
