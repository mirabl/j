import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class ColorfulRoadSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        String road = (String) reader.next(String.class);
        reader.close();

        ColorfulRoad solver = new ColorfulRoad();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.getMin(road));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
