public class Problem {
    private String m_ProblemName;
    private String m_Directory;
    private static int nextId;

    private int id;

    public void setID() {
        id = nextId;
        nextId++;
    }

    public static int getNextId() {
        return nextId;
    }

    public String getM_ProblemName() {
        return m_ProblemName;
    }

    public void setM_ProblemName(String m_ProblemName) {
        this.m_ProblemName = m_ProblemName;
    }

    public String getM_Directory() {
        return m_Directory;
    }

    public void setM_Directory(String m_Directory) {
        this.m_Directory = m_Directory;
    }

    public Problem(String problemName, String directory) {
        this.m_Directory = directory;
        this.m_ProblemName = problemName;
    }
}
