package ru.morecode.jrpg;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import ru.morecode.jrpg.subclasses.SceneSizeChangeListener;
import ru.morecode.jrpg.subclasses.StartScene;

public class MainMenuController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button buttonExit;

    @FXML
    private Button buttonLoad;

    @FXML
    private Button buttonNewGame;


    @FXML
    void initialize() {
        buttonExit.setOnAction(actionEvent ->{
            Platform.exit();
        } );
        buttonLoad.setOnAction(actionEvent ->{
            System.out.println("Load game");
        } );
        buttonNewGame.setOnAction(actionEvent ->{
            buttonNewGame.getScene().getWindow().hide();

            StartScene scene = new StartScene("game-window.fxml");
            scene.start();
        } );
    }

}
