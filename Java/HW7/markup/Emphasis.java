package markup;
import java.util.List;

public class Emphasis extends AbstractElements {
	public void toHtml(StringBuilder str) {
		inH(str, "em");
	}
	public Emphasis(List <threeAble> list) {
		this.list = list;
	}
	public void toMarkdown(StringBuilder str) {
		inM(str, "*");
	}
	public void toTex(StringBuilder str) {
		inT(str, "\\emph");
	}
}