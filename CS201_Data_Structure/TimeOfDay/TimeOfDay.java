import java.sql.Time;

public class TimeOfDay{
   private int hour;
   private int minute;
   public int second;
   public TimeOfDay(int hour, int minute, int second){
      this.hour = hour;
      this.second = second;
      this.minute = minute;
   }
   public TimeOfDay(int secondsince){
      this.second = secondsince;
   }



}