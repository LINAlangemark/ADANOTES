package plan;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

// Aktivitet class to represent an activity with an event number, task name, and duration
class Aktivitet {
    int event;
    String task;
    int duration;

    // Constructor to initialize the Aktivitet object with the given event number, task name, and duration
    public Aktivitet(int event, String task, int duration) {
        this.event = event;
        this.task = task;
        this.duration = duration;
    }

    public int getEvent() {
        return event;
    }

    public String getTask() {
        return task;
    }

    public int getDuration() {
        return duration;
    }

    @Override // Override the toString method to print the Aktivitet object in a readable format
    public String toString() {
        return "Aktivitet{" +
                "event=" + event +
                ", task='" + task + '\'' +
                ", duration=" + duration +
                '}';
    }
}

// AktivitetsPlan class to read activities from a file, calculate the average duration, and determine the critical path
public class AktivitetsPlan {
    public static List<Aktivitet> læsAktiviteterFraFil(String fileName) throws IOException {            // Read activities from a file and return a list of Aktivitet objects
        List<Aktivitet> aktiviteter = new ArrayList<>();                                                // Create a list to store Aktivitet objects
        try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {                        // Create a BufferedReader to read the file
            String line;                                                                                // Read the file line by line       
            while ((line = br.readLine()) != null) {                                                    // Read the file line by line
                String[] data = line.split(" ");                                                  // Split the line by space
                for (String activityData : data) {                                                      // Iterate through the split data
                    String[] activityParts = activityData.split(";");                             // Split the activity data by semicolon
                    if (activityParts.length != 3) {                                                    // Check if the activity format is valid
                        System.err.println("Invalid activity format: " + activityData);                 // Print an error message if the activity format is invalid
                        continue;                                                                       // Skip the current activity if the format is invalid
                    }
                    try {                                                                               // Try to parse the event number and duration
                        int event = Integer.parseInt(activityParts[0].trim());                          // Parse the event number
                        String task = activityParts[1].trim();                                          // Get the task name
                        int duration = Integer.parseInt(activityParts[2].trim());                       // Parse the duration
                        aktiviteter.add(new Aktivitet(event, task, duration));                          // Add the Aktivitet object to the list
                    } catch (NumberFormatException e) {                                                 // Catch the NumberFormatException if the number format is invalid
                        System.err.println("Invalid number format in activity: " + activityData);       // Print an error message if the number format is invalid
                    }
                }
            }
        }
        return aktiviteter;
    }

    public static void main(String[] args) {                                                           // Main method to read activities from a file, calculate the average duration, and determine the critical path
        try {                                                                                          // Try to read activities from a file
            List<Aktivitet> tabel = læsAktiviteterFraFil("C:\\Users\\Lenovo\\OneDrive - Syddansk Universitet\\5. semester\\Algoritmer og datastrukturer\\plan\\data.txt");

            // Print the number of activities
            System.out.println("Number of activities: " + tabel.size());                              // Print the number of activities

            // Calculate and print the average duration
            double totalDuration = 0;                                                                 // Initialize the total duration
            for (Aktivitet aktivitet : tabel) {                                                       // Iterate through the activities
                totalDuration += aktivitet.getDuration();                                             // Add the duration of the current activity to the total duration
            }
            double averageDuration = totalDuration / tabel.size();                                    // Calculate the average duration
            System.out.println("Average duration: " + averageDuration + " days");                     // Print the average duration

            // Determine the critical path
            List<Aktivitet> criticalPath = new ArrayList<>();                                         // Create a list to store the activities in the critical path
            int currentEvent = 1;                                                                     // Initialize the current event number
            while (true) {                                                                            // Iterate through the events
                List<Aktivitet> currentEventActivities = new ArrayList<>();                           // Create a list to store the activities of the current event
                for (Aktivitet aktivitet : tabel) {                                                   // Iterate through the activities
                    if (aktivitet.getEvent() == currentEvent) {                                       // Check if the activity belongs to the current event
                        currentEventActivities.add(aktivitet);                                        // Add the activity to the list of current event activities
                    }
                }
                if (currentEventActivities.isEmpty()) {                                               // Check if there are no activities for the current event
                    break;                                                                            // Break the loop if there are no activities for the current event
                }
                Aktivitet longestActivity = currentEventActivities.get(0);                      // Initialize the longest activity with the first activity of the current event
                for (Aktivitet aktivitet : currentEventActivities) {                                  // Iterate through the activities of the current event
                    if (aktivitet.getDuration() > longestActivity.getDuration()) {                    // Check if the duration of the current activity is longer than the duration of the longest activity
                        longestActivity = aktivitet;                                                  // Update the longest activity if the current activity is longer
                    }
                }
                criticalPath.add(longestActivity);                                                    // Add the longest activity to the critical path
                currentEvent++;                                                                       // Move to the next event
            }

            // Print the critical path and its duration
            int criticalPathDuration = 0;                                                             // Initialize the critical path duration
            System.out.print("Critical path: ");                                                    // Print the critical path
            for (Aktivitet aktivitet : criticalPath) {                                                // Iterate through the activities in the critical path
                System.out.print(aktivitet.getTask() + " ");                                          // Print the task name of the current activity
                criticalPathDuration += aktivitet.getDuration();                                      // Add the duration of the current activity to the critical path duration
            }
            System.out.println("\nCritical path duration: " + criticalPathDuration + " days");        // Print the critical path duration

        } catch (IOException e) {                                                                     // Catch the IOException if the file is not found
            System.err.println("File not found: " + e.getMessage());                                  // Print an error message if the file is not found
        }
    }
}