package ru.morecode.jrpg;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.application.Platform;
import javafx.fxml.FXML;
import javafx.scene.control.Button;

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
            System.out.println("New game");
        } );
    }

}
