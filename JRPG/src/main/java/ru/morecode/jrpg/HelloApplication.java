package ru.morecode.jrpg;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import ru.morecode.jrpg.subclasses.SceneSizeChangeListener;
import ru.morecode.jrpg.subclasses.StartScene;

import java.io.IOException;

public class HelloApplication extends Application {

    // если раскомментировать этот код, то программа запустится
    /*private void letterbox(final Scene scene, final Pane contentPane) {
        final double initWidth  = scene.getWidth();
        final double initHeight = scene.getHeight();
        final double ratio      = initWidth / initHeight;

        SceneSizeChangeListener sizeListener = new SceneSizeChangeListener(scene, ratio, initHeight, initWidth, contentPane);
        scene.widthProperty().addListener(sizeListener);
        scene.heightProperty().addListener(sizeListener);
    }*/

    @Override
    public void start(Stage stage) {
        // если раскомментировать этот код, то программа запустится
        /*FXMLLoader fxmlLoader = new FXMLLoader();
        fxmlLoader.setLocation(getClass().getResource("main-menu.fxml"));

        Pane root;
        try {
            root = fxmlLoader.load();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        Scene scene = new Scene(new Group(root));
        stage.setScene(scene);
        stage.setTitle("Main Menu");
        stage.show();
        stage.setFullScreenExitHint("");
        letterbox(scene, root);
        stage.setFullScreen(true);*/

        StartScene scene = new StartScene(stage, "main-menu.fxml");
        scene.start();
    }

    public static void main(String[] args) {
        launch();
    }
}