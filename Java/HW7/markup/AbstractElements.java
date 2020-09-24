package markup;
import java.util.List;

public abstract class AbstractElements implements threeAble {
	protected List<threeAble> list;
	protected void inH(StringBuilder str, String raz) { 
		if (raz.length() != 0) {
			str.append("<" + raz + ">");
		}
		for (int i = 0; i < list.size(); i++) {
			list.get(i).toHtml(str);
		}
		if (raz.length() != 0) {
			str.append("<" + "/" + raz + ">");
		}
	}
	protected void inM(StringBuilder str, String raz) { 
		str.append(raz);
		for (int i = 0; i < list.size(); i++) {
			list.get(i).toMarkdown(str);
		}
		str.append(raz);
	}
	protected void inT(StringBuilder str, String raz) { 
		if (raz.length() != 0) {
			str.append(raz + "{" );
		}
		for (int i = 0; i < list.size(); i++) {
			list.get(i).toTex(str);
		}
		if (raz.length() != 0) {
			str.append("}");
		}
	}
	abstract public void toMarkdown(StringBuilder str);
	abstract public void toHtml(StringBuilder str);
	abstract public void toTex(StringBuilder str);
}
