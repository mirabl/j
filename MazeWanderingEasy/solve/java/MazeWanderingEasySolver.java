import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class MazeWanderingEasySolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        List<String> mazeBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] maze = new String[mazeBoxed.size()];
        for (int _i = 0; _i < mazeBoxed.size(); ++_i)
            maze[_i] = mazeBoxed.get(_i);
        reader.close();

        MazeWanderingEasy solver = new MazeWanderingEasy();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.decisions(maze));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
