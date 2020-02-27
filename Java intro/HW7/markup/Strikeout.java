package markup;
import java.util.List;

public class Strikeout extends AbstractElements {
	public void toHtml(StringBuilder str) {
		inH(str, "s");
	}
	public void toTex(StringBuilder str) {
		inT(str, "\\textst");
	}
	public Strikeout(List <threeAble> list) {
		this.list = list;
	}
	public void toMarkdown(StringBuilder str) {
		inM(str, "~");
	}
}