public class Aktivitet
{
    private int event;
    private String task;
    private int duration;

    public Aktivitet() {}

    public Aktivitet (int e, String t, int d)
    {
        event = e;
        task = t;
        duration = d;
    }

    public int getEvent()
    {
        return event;
    }

    public String getTask()
    {
        return task;
    }

    public int getDuration()
    {
        return duration;
    }
}
