import numpy as np


class PointBrowser:
    """
    Click on a point to select and highlight it -- the data that
    generated the point will be shown in the lower axes.  Use the 'n'
    and 'p' keys to browse through the next and previous points
    """

    def __init__(self):
        self.lastind = 0

        self.text = AX.text(0.05, 0.95, 'selected: none',
                            transform=AX.transAxes, va='top')
        self.selected, = AX.plot([XS[0]], [YS[0]], 'o', ms=12, alpha=0.4,
                                 color='yellow', visible=False)

    def onpress(self, event):
        """
        Handle point click
        """

        if self.lastind is None:
            return
        if event.key not in ('n', 'p'):
            return
        if event.key == 'n':
            inc = 1
        else:
            inc = -1

        self.lastind += inc
        self.lastind = np.clip(self.lastind, 0, len(XS) - 1)
        self.update()

    def onpick(self, event) -> bool:
        """
        Handle point selection
        """

        if event.artist != LINE:
            return True

        n = len(event.ind)
        if not n:
            return True

        # the click locations
        x = event.mouseevent.xdata
        y = event.mouseevent.ydata

        distances = np.hypot(x - XS[event.ind], y - YS[event.ind])
        indmin = distances.argmin()
        dataind = event.ind[indmin]

        self.lastind = dataind
        self.update()

    def update(self):
        """
        Handle update for timeseries
        """

        if self.lastind is None:
            return

        dataind = self.lastind

        AX2.cla()
        AX2.plot(X[dataind])

        AX2.text(0.05, 0.9, 'mu=%1.3f\nsigma=%1.3f' % (XS[dataind], YS[dataind]),
                 transform=AX2.transAxes, va='top')
        AX2.set_ylim(-0.5, 1.5)
        self.selected.set_visible(True)
        self.selected.set_data(XS[dataind], YS[dataind])

        self.text.set_text('selected: %d' % dataind)
        FIG.canvas.draw()


if __name__ == '__main__':
    import matplotlib.pyplot as plt
    # Fixing random state for reproducibility
    np.random.seed(19680801)

    X = np.random.rand(100, 200)
    XS = np.mean(X, axis=1)
    YS = np.std(X, axis=1)

    FIG, (AX, AX2) = plt.subplots(2, 1)
    AX.set_title('click on point to plot time series')
    LINE, = AX.plot(XS, YS, 'o', picker=5)  # 5 points tolerance

    BROWSER = PointBrowser()

    FIG.canvas.mpl_connect('pick_event', BROWSER.onpick)
    FIG.canvas.mpl_connect('key_press_event', BROWSER.onpress)

    plt.show()
