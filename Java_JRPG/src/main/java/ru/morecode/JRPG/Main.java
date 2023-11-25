package ru.morecode.JRPG;

import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class Main {

    public static final String PATH_TO_PROPERTIES = "src/main/resources/config.properties";
    public static void dbExample(Properties prop) {
        Connection connection = null;
        try {
            connection = DriverManager.getConnection(prop.getProperty("database.url"));
            Statement statement = connection.createStatement();
            statement.setQueryTimeout(30);
            statement.executeUpdate("drop table if exists person");
            statement.executeUpdate("create table person (id integer, name string)");
            statement.executeUpdate("insert into person values(1, 'leo')");
            statement.executeUpdate("insert into person values(2, 'yui')");
            ResultSet rs = statement.executeQuery("select * from person");
            while (rs.next()) {
                System.out.println("name = " + rs.getString("name"));
                System.out.println("id = " + rs.getInt("id"));
            }
        } catch (SQLException e) {
            System.err.println(e.getMessage());
        } finally {
            try {
                if (connection != null)
                    connection.close();
            } catch (SQLException e) {
                System.err.println(e);
            }
        }
    }
    public static void main(String[] args){
        System.out.println("Hello World");

        FileInputStream fileInputStream;
        Properties prop = new Properties();
        try {
            fileInputStream = new FileInputStream(PATH_TO_PROPERTIES);
            prop.load(fileInputStream);
            dbExample(prop);
        } catch (IOException e) {
            System.out.println("Ошибка в программе: файл " + PATH_TO_PROPERTIES + " не обнаружено");
            e.printStackTrace();
        }
    }
}
