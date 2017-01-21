import java.io.FileReader;
import java.io.FileWriter;

import java.util.List;
import java.util.ArrayList;

import org.topcoder.TopcoderReader;
import org.topcoder.TopcoderWriter;
import org.topcoder.TypeRef;

public class ThreeTeleportsSolver {
    public static void main(String[] args) {
    try {
        TopcoderReader reader = new TopcoderReader(new FileReader(args[0]));
        int xMe = (Integer) reader.next(Integer.class);
        reader.next();
        
        int yMe = (Integer) reader.next(Integer.class);
        reader.next();
        
        int xHome = (Integer) reader.next(Integer.class);
        reader.next();
        
        int yHome = (Integer) reader.next(Integer.class);
        reader.next();
        
        List<String> teleportsBoxed = (List<String>) reader.next(new TypeRef<List<String>>(){}.getType());
        String[] teleports = new String[teleportsBoxed.size()];
        for (int _i = 0; _i < teleportsBoxed.size(); ++_i)
            teleports[_i] = teleportsBoxed.get(_i);
        reader.close();

        ThreeTeleports solver = new ThreeTeleports();
        TopcoderWriter writer = new TopcoderWriter(new FileWriter(args[1]));
        writer.write(solver.shortestDistance(xMe, yMe, xHome, yHome, teleports));
        writer.close();
    } catch (Exception err) {
        err.printStackTrace(System.err);
    }
    }
}
