package ru.morecode.JRPG.field;

public class LabirintField extends Field{

    private String id, event_;

    public LabirintField(int size, String id, String event_){
        super(size);
        this.id = id;
        this.event_ = event_;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setEvent_(String event_) {
        this.event_ = event_;
    }

    public String getId() {
        return id;
    }

    public String getEvent_() {
        return event_;
    }
}
