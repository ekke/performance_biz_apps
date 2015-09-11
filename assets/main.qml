
import bb.cascades 1.4
import bb.system 1.2

TabbedPane {
    id: rootPane
    
    attachedObjects: [
        SystemToast {
            id: infoToast
            body: "test"
            icon: "asset:///images/icon.png"
            position: SystemUiPosition.TopCenter
            onFinished: {
                //
            }
        }
    ]
    
    Tab {
        id: uniqueIndexTab
        title: "Unique Index"
        description: "checks for unique index via StringList or Map"
        UniqueIndexPage {
        }
    } // uniqueIndexTab
    
    Tab {
        title: "stay tuned for more"
        Page {
            Container {
                Label {
                    text: "TBD"
                }
            }
        }
    }
    
    function showInfo(infotext) {
        infoToast.body = infotext
        infoToast.show()
    }
    
    
    
} // rootPane



