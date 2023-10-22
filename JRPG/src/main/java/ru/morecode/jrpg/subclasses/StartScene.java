package ru.morecode.jrpg.subclasses;

import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;


import java.io.IOException;


// Класс для запуска сцен

public class StartScene {

    FXMLLoader fxmlLoader;
    Pane root;
    Scene scene;
    Stage stage;

    private void letterbox(final Scene scene, final Pane contentPane) {
        final double initWidth  = scene.getWidth();
        final double initHeight = scene.getHeight();
        final double ratio      = initWidth / initHeight;

        SceneSizeChangeListener sizeListener = new SceneSizeChangeListener(scene, ratio, initHeight, initWidth, contentPane);
        scene.widthProperty().addListener(sizeListener);
        scene.heightProperty().addListener(sizeListener);
    }
    public StartScene(Stage stage, String nameFXML){
        fxmlLoader = new FXMLLoader();
        this.stage = stage;
        //Вероятно проблема здесь так как при выводе location выводится null
        fxmlLoader.setLocation(getClass().getResource(nameFXML));
        System.out.println(fxmlLoader.getLocation());
        Pane root;
        try {
            // программа падает на этой строке
            root = fxmlLoader.load();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        scene = new Scene(new Group(root));
    }

    public void start(){
        stage.setScene(scene);
        stage.show();
        stage.setFullScreenExitHint("");
        letterbox(scene, root);
        stage.setFullScreen(true);
    }
}
