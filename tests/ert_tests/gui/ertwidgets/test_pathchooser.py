from qtpy.QtWidgets import QFileDialog
from ert_gui.ertwidgets.pathchooser import PathChooser
from ert_gui.ertwidgets.models.path_model import PathModel


def test_selectfile(qtbot, tmpdir, monkeypatch):
    model = PathModel(tmpdir, must_be_a_file=True)
    widget = PathChooser(model)
    widget.show()
    qtbot.addWidget(widget)

    monkeypatch.setattr(QFileDialog, "getOpenFileName", lambda *args: ("foo", "bar"))
    qtbot.waitExposed(widget)
    widget.selectPath()
    assert "foo" == model.getPath(), f"Unexpected path {model.getPath()}"


def test_selectfile_cancel(qtbot, tmpdir, monkeypatch):
    model = PathModel(tmpdir, must_be_a_file=True)
    widget = PathChooser(model)
    widget.show()
    qtbot.addWidget(widget)

    monkeypatch.setattr(QFileDialog, "getOpenFileName", lambda *args: ("", ""))
    qtbot.waitExposed(widget)
    widget.selectPath()
    assert tmpdir == model.getPath(), f"Unexpected path {model.getPath()}"


def test_selectdirectory(qtbot, tmpdir, monkeypatch):
    model = PathModel(tmpdir, must_be_a_file=False)
    widget = PathChooser(model)
    widget.show()
    qtbot.addWidget(widget)

    monkeypatch.setattr(QFileDialog, "getExistingDirectory", lambda *args: "foo")

    qtbot.waitExposed(widget)
    widget.selectPath()
    assert "foo" == model.getPath(), f"Unexpected path {model.getPath()}"


def test_selectdirectory_cancel(qtbot, tmpdir, monkeypatch):
    model = PathModel(tmpdir, must_be_a_file=False)
    widget = PathChooser(model)
    widget.show()
    qtbot.addWidget(widget)

    monkeypatch.setattr(QFileDialog, "getExistingDirectory", lambda *args: "")

    qtbot.waitExposed(widget)
    widget.selectPath()
    assert tmpdir == model.getPath(), f"Unexpected path {model.getPath()}"
