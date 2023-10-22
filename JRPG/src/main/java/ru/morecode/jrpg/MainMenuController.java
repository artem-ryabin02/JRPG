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

    private void letterbox(final Scene scene, final Pane contentPane) {
        final double initWidth  = scene.getWidth();
        final double initHeight = scene.getHeight();
        final double ratio      = initWidth / initHeight;

        SceneSizeChangeListener sizeListener = new SceneSizeChangeListener(scene, ratio, initHeight, initWidth, contentPane);
        scene.widthProperty().addListener(sizeListener);
        scene.heightProperty().addListener(sizeListener);
    }
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

            FXMLLoader fxmlLoader = new FXMLLoader();
            fxmlLoader.setLocation(getClass().getResource("game-window.fxml"));
            Stage stage = new Stage();
            Pane root;
            try {
                root = fxmlLoader.load();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            Scene scene = new Scene(new Group(root));
            stage.setScene(scene);
            stage.setTitle("Game window");
            stage.show();
            stage.setFullScreenExitHint("");
            letterbox(scene, root);
            stage.setFullScreen(true);
        } );
    }

}
