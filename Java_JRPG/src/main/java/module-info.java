module ru.morecode.JRPG {
    requires javafx.controls;
    requires javafx.fxml;
    requires java.sql;


    opens ru.morecode.JRPG to javafx.fxml;
    exports ru.morecode.JRPG.field;
    exports ru.morecode.JRPG.location;
}