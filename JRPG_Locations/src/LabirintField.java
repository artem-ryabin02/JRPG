public class LabirintField {

    private String id, event_;

    LabirintField(String id, String event_){
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
