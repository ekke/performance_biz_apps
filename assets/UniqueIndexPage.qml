import bb.cascades 1.4
import org.ekkescorner.common 1.0

Page {
    id: uniqueIndexPage
    titleBar: TitleBar {
        title: "Check Index if Unique"
    }

    actions: [
        ActionItem {
            title: "QStringList"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                myLabel4StringList.text = "...work in progress...please wait..."
                delayedStringList.start()
            }
        },
        ActionItem {
            title: "QVariantMap"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                myLabel4VariantMap.text = "...work in progress...please wait..."
                delayedVariantMap.start()
            }
        },
        ActionItem {
            title: "QMap"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                myLabel4Map.text = "...work in progress...please wait..."
                delayedMap.start()
            }
        },
        ActionItem {
            title: "QHash"
            ActionBar.placement: ActionBarPlacement.OnBar
            onTriggered: {
                myLabel4Map.text = "...work in progress...please wait..."
                delayedHash.start()
            }
        }
    ]

    attachedObjects: [
        QTimer {
            id: delayedStringList
            interval: 300
            singleShot: true
            onTimeout: {
                // delayed start so the Label has enough time to redraw text
                app.checkIndexQStringList()
            }
        },
        QTimer {
            id: delayedVariantMap
            interval: 300
            singleShot: true
            onTimeout: {
                // delayed start so the Label has enough time to redraw text
                app.checkIndexQVariantMap()
            }
        },
        QTimer {
            id: delayedMap
            interval: 300
            singleShot: true
            onTimeout: {
                // delayed start so the Label has enough time to redraw text
                app.checkIndexQMap()
            }
        },
        QTimer {
            id: delayedHash
            interval: 300
            singleShot: true
            onTimeout: {
                // delayed start so the Label has enough time to redraw text
                app.checkIndexQHash()
            }
        }
    ]

    ScrollView {
        id: scrollView

        Container {
            id: outerContainer
            topPadding: ui.du(6.0)
            leftPadding: ui.du(4.0)
            rightPadding: ui.du(4.0)
            Label {
                text: "Please select an Action from ActionBar and wait for feedback."
                textStyle.color: Color.DarkGray
                multiline: true
            }
            Divider {
            }
            Label {
                id: myLabel4StringList
                text: ""
                textStyle.fontSize: FontSize.Large
                textStyle.color: ui.palette.primary
                multiline: true
            }
            Divider {
            }
            Label {
                id: myLabel4VariantMap
                text: ""
                textStyle.fontSize: FontSize.Large
                textStyle.color: ui.palette.primary
                multiline: true
            }
            Divider {
            }
            Label {
                id: myLabel4Map
                text: ""
                textStyle.fontSize: FontSize.Large
                textStyle.color: ui.palette.primary
                multiline: true
            }
            Divider {
            }
            Label {
                id: myLabel4Hash
                text: ""
                textStyle.fontSize: FontSize.Large
                textStyle.color: ui.palette.primary
                multiline: true
            }
            Divider {
            }
            Label {
                text: "Measures processing time to loop through 50k records and to check if there are duplicates."
                multiline: true
                textStyle.color: Color.DarkGray
            }
        } // outerContainer

    } // scrollView

    function onDoneStringList(info) {
        myLabel4StringList.text = info
        rootPane.showInfo("Work done")
    }
    function onDoneVariantMap(info) {
        myLabel4VariantMap.text = info
        rootPane.showInfo("Work done")
    }
    function onDoneMap(info) {
        myLabel4Map.text = info
        rootPane.showInfo("Work done")
    }
    function onDoneHash(info) {
        myLabel4Hash.text = info
        rootPane.showInfo("Work done")
    }

    onCreationCompleted: {
        app.doneStringList.connect(onDoneStringList)
        app.doneVariantMap.connect(onDoneVariantMap)
        app.doneMap.connect(onDoneMap)
        app.doneHash.connect(onDoneHash)
    }

} // uniqueIndexPage
