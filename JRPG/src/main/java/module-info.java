module ru.morecode.jrpg {
    requires javafx.controls;
    requires javafx.fxml;

    requires org.controlsfx.controls;
    requires com.almasb.fxgl.all;
    requires java.sql;
    requires org.xerial.sqlitejdbc;

    opens ru.morecode.jrpg to javafx.fxml;
    exports ru.morecode.jrpg;
    exports ru.morecode.jrpg.subclasses;
    opens ru.morecode.jrpg.subclasses to javafx.fxml;
}
