OpenMS
=======

[![License (3-Clause BSD)](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg?logo=data:image/svg+xml;base64,PD94bWwgdmVyc2lvbj0iMS4wIiBlbIt provides built-in algorithms for de-novo identification and database search,
as well as adapters to other state-of-the art tools like X!Tandem, Mascot,
Comet, etc. It supports easy integration of OpenMS built tools into workflow
engines like KNIME, Galaxy, WS-Pgrade, and TOPPAS via the TOPPtools concept and
a unified parameter handling via a 'common tool description' (CTD) scheme.

With pyOpenMS, OpenMS offers Python bindings to a large part of the OpenMS API
to enable rapid algorithm development. OpenMS supports the Proteomics Standard
Initiative (PSI) formats for MS data. The main contributors of OpenMS are
currently the Eberhard-Karls-Universität in Tübingen, the Freie Universität
Berlin, and the ETH Zürich.

Features
--------
- Core C++ library under three-clause BSD licence using modern C++17
- Python bindings to the C++ API through pyOpenMS
- Major community file formats supported (mzML, mzXML, mzIdentXML, pepXML, mzTab, etc.)
- Over 150+ individual analysis tools (TOPP Tools), covering most MS and LC-MS data processing and mining tasks
- Powerful 1D, 2D and 3D visualization tools (TOPPView)
- Support for most MS identification and quantification workflows (targeted, DIA, label-free, isobaric and stable isotope)
- Support for all major platforms (Windows [XP, 7, 8, 10], macOS and Linux)

Documentation
-------------

Users and developers should start by reading the [OpenMS documentation](https://openms.readthedocs.io/en/latest). OpenMS
API reference documentation and advanced developer doxygen documentation can be browsed [here](https://abibuilder.cs.uni-tuebingen.de/archive/openms/Documentation/release/latest/html/index.html).

openms.readthedocs.io documentation aims at being an entry point for users and developers alike. It is trying to be mostly version-independent and therefore
only consists of one main branch. We may introduce tags for older releases in the future.

The OpenMS API reference has several endpoints:

1. [`nightly`](https://abibuilder.cs.uni-tuebingen.de/archive/openms/Documentation/nightly/html/index.html): OpenMS API reference and advanced developer documentation of nightly releases.
2. [`release/latest`](https://abibuilder.cs.uni-tuebingen.de/archive/openms/Documentation/release/latest/html/index.html) : OpenMS API reference and advanced developer documentation of latest stable release.
3. [`release/${version}`](https://abibuilder.cs.uni-tuebingen.de/archive/openms/Documentation/release/latest/html/index.html) : OpenMS API reference and advanced developer documentation of an older version.

Documentation for the Python bindings pyOpenMS can be found on the [pyOpenMS online documentation](https://pyopenms.readthedocs.io).

Citation
--------
Please cite:

Rost HL, Sachsenberg T, Aiche S, Bielow C et al. OpenMS: a flexible open-source software platform for mass spectrometry data analysis. Nat Meth. 2016; 13, 9: 741-748. doi:10.1038/nmeth.3959.

The file [AUTHORS](AUTHORS) contains a list of all authors who worked on OpenMS.

Licence
-------
OpenMS is released under the [three clause BSD licence](LICENSE).
